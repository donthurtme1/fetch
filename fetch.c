#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include "ascii.h"

static const char *ascii_distro = arch_ascii;

static const char field_format[] = "\e[%s;1m%s\e[0m: %s\e[B\e[43G";
static const char simple_format[] = "\e[%s;1m%s\e[0m %s\e[B\e[43G";
static char storage_bar[12] = "------------";

static const char *output_format[] = {
	"\e[%s;1m󰍹  \e[0m\e[90mDistro    \e[0m%s",
	"\e[%s;1m  \e[0m\e[90mPackages  \e[0m%s",
	"\e[%s;1m  \e[0m\e[90mTerminal  \e[0m%s",
	"\e[%s;1m  \e[0m\e[90mUptime    \e[0m%s",
	"\e[%s;1m  \e[0m\e[90mBrowser   \e[0m%s",
	"\e[%s;1m  \e[0m\e[90mCPU       \e[0m%s",
	"\e[%s;1m  \e[0m\e[90mStorage   \e[%sm%d / %d GiB",
	NULL
};

static const char *output_value[] = {
	"Arch Linux",
	NULL,
	"Alacritty",
	NULL,
	"Firefox",
	"AMD Ryzen 3",
	"0",
	NULL
};

/* Set "ascii_distro" to specified distro if it exists. */
void setdistro(const char *distro_str) {
	if (distro_str[0] == 'a') ascii_distro = arch_ascii;
	if (distro_str[0] == 'g') ascii_distro = gentoo_ascii;
	if (distro_str[0] == 'f') {
		if (distro_str[1] == 'a') ascii_distro = femboy_arch;
		if (distro_str[1] == 'g') ascii_distro = femboy_gentoo;
	}
}

char *concat(const char *restrict start, const char *restrict end) {
	int start_size = 0, end_size = 0;
	while (start[++start_size]) {}; /* Pre increment counts null terminator, but misses first value. */
	while (end[end_size++]) {};		/* Post increment counts including the null terminator. */

	char *s = (char *)malloc(start_size + end_size);
	int i = 0;
	for (; i < start_size; i++) { s[i] = start[i]; }
	i = 0;
	for (; i < end_size; i++) { s[start_size + i] = end[i]; }
	return s;
}

char getarg(const char *arg) {
	if (arg == NULL) return 0;
	if (arg[0] == '-') return arg[1];
	return 1;
}

int main(int argc, char *argv[]) {
	int pipefd[2];
	pipe(pipefd);

	/* Command line arguments. */
	_Bool set_distro = 0, vertical = 0;
	const char *colour = "36";

	char c;
	int i = 0;
	while ((c = getarg(argv[++i]))) {
		if (c == 'h') printf("help\n"); /* TODO */
		else if (c == 'c') colour = argv[++i];
		else if (c == 'd') setdistro(argv[++i]);
		else if (c == 'v') vertical = 1;
	}

	/* Setup */
	struct winsize term_size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &term_size);

	const char *fetch_cache_dir = concat(getenv("HOME"), "/.cache/fetch/");
	mkdir(fetch_cache_dir, S_IRWXU);

	/* Distro */
	/*
	if (fork() == 0) {
		dup2(pipefd[1], STDOUT_FILENO);
		char *s = malloc(20);
		unsigned long i;
		FILE *fp = fopen("/etc/os-release", "r");
		getline(&s, &i, fp);
		fclose(fp);
		printf("%s Linux", s);

		return 0;
	}

	char *distro_str;
	dup2(pipefd[0], STDIN_FILENO);
	wait(NULL);
	scanf("%2ms", &distro_str);
	output_value[0] = distro_str;
	*/

	/* Packages */
	if (fork() == 0) {
		dup2(pipefd[1], STDOUT_FILENO);
		system("pacman -Qq | wc -l");
		return 0;
	}

	char *packages_str;
	dup2(pipefd[0], STDIN_FILENO);
	scanf("%ms", &packages_str);
	output_value[1] = concat(packages_str, " pacman");

	/* Uptime */
	struct sysinfo sys_info;
	char uptime_str[5] = "00:00";
	sysinfo(&sys_info);
	int upmins = (sys_info.uptime / 60) % 60;
	int uphours = (sys_info.uptime / 3600) % 60;

	uptime_str[4] = (upmins % 10) + '0';
	uptime_str[3] = (upmins / 10) + '0';
	uptime_str[1] = (uphours % 10) + '0';
	uptime_str[0] = (uphours / 10) + '0';
	output_value[3] = uptime_str;

	/* Storage */
	int total_storage, used_storage, storage_percent;
	const char *fetch_storage = concat(fetch_cache_dir, "storage");
	
	if (system(concat("df --total | grep home > ", fetch_storage)) >= 0) {
		FILE *fstorage = fopen(fetch_storage, "r");
		fscanf(fstorage, "%*s %d %d %*s %d", &total_storage, &used_storage, &storage_percent);
		fclose(fstorage);
	}

	total_storage = total_storage >> 20;
	used_storage = used_storage >> 20;
	int bar_percent = ((storage_percent * 12) / 100) + 1;
	for (int i = 0; i < bar_percent; i++) {
		memcpy(&storage_bar[i], "#", 1);
	}

	/* Print stuff. 18*/
	if (vertical) {
		int yoffset = (term_size.ws_row - 18) >> 1;
		for (int i = 0; i < yoffset; i++) {
			putc('\n', stdout);
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\e[15A");
	i = 0;
	printf("\e[%s;1m", colour);
	if (!vertical) {
		printf("\e[2B\e[8C%s", simple_artix);

		printf("\e[11A\e[31G");
		while (output_format[i]) {
			printf("\e[B\e[31G");
			printf(output_format[i], colour, output_value[i], used_storage, total_storage);
			i++;
		}

		printf("\e[2B\e[31G");
		printf("\e[30m███\e[31m███\e[32m███\e[33m███\e[34m███\e[35m███\e[36m███\e[37m███");
		printf("\e[B\e[31G");
		printf("\e[90m███\e[91m███\e[92m███\e[93m███\e[94m███\e[95m███\e[96m███\e[97m███");

		printf("\e[4E");
	} else {
		printf("\e[B\e[%dG%s", (term_size.ws_col / 2) - 6, space_invader_offset);

		printf("\e[2B\e[%dG", (term_size.ws_col / 2) - 12);
		printf("\e[30m███\e[31m███\e[32m███\e[33m███\e[34m███\e[35m███\e[36m███\e[37m███");
		printf("\e[B\e[%dG", (term_size.ws_col / 2) - 12);
		printf("\e[90m███\e[91m███\e[92m███\e[93m███\e[94m███\e[95m███\e[96m███\e[97m███");

		printf("\e[B");
		while (output_format[i]) {
			printf("\e[B\e[%dG", (term_size.ws_col / 2) - 12);
			printf(output_format[i], colour, output_value[i], used_storage, total_storage);
			i++;
		}
		printf("\n\n");
	}

	return 0;
}

//printf("\e[B\e[43G"); // Cursor position.
/* TODO: make cursor position and text colour dependant on selected ascii art. */
/*
printf("\e[%s;1m%s\e[0m\e[B\e[43G%s\e[B\e[43G", colour, "Simplefetch", "~~~~~~~~~~~"); // Title.
printf(field_format, colour, "Distro", "Arch Linux");
printf(field_format, colour, "Window Manager", "dwl");
printf(field_format, colour, "Packages", "? - pacman");
printf(field_format, colour, "Terminal", "Alacritty");
printf(field_format, colour, "Terminal Font", "Hack Nerd Font");
printf(field_format, colour, "Shell", "bash 5.2.26");
printf(field_format, colour, "CPU", "AMD Ryzen 3 3200G @ 3.6 GHz");
printf(field_format, colour, "GPU", "AMD Radeon RX 6600");
printf(field_format, colour, "Memory", "16 GiB");
printf("\e[%s;1mStorage\e[0m: %d / %d GiB\e[53C\e[19D[%s] (%d%%)\e[B\e[43G", colour, used_storage, total_storage, storage_bar, storage_percent);

printf("\e[B\e[43G");
printf("\e[30m███\e[31m███\e[32m███\e[33m███\e[34m███\e[35m███\e[36m███\e[37m███\e[B\e[43G");
printf("\e[90m███\e[91m███\e[92m███\e[93m███\e[94m███\e[95m███\e[96m███\e[97m███\e[B\e[43G");
printf("\e[4E");
*/

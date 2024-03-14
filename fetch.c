#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ascii.h"

/*
static const char partition_table[] = "\e[B\e[47G\
sda                  [931.5 GiB]\e[B\e[47G\
├─sda1   /boot   [##-----------]  (15%)   - /     1 GiB\e[B\e[47G\
├─sda2   [SWAP]  [-------------]  ( 0%)   - /    16 GiB\e[B\e[47G\
├─sda3   /       [###----------]  (34%)  13 /    40 GiB\e[B\e[47G\
└─sda4   /home   [#------------]  ( 7%)  19 / 874.5 GiB";
*/

static const char *ascii_distro = arch_ascii;

static const char field_format[] = "\e[%s;1m%s\e[0m: %s\e[B\e[43G";
static char storage_bar[12] = "------------";

/* Set "ascii_distro" to specified distro if it exists. */
void setdistro(const char *distro_str) {
	if (distro_str[0] == 'a') ascii_distro = arch_ascii;
	if (distro_str[0] == 'g') ascii_distro = gentoo_ascii;
	if (distro_str[0] == 'f') {
		if (distro_str[1] == 'a') ascii_distro = femboy_arch;
		if (distro_str[1] == 'g') ascii_distro = femboy_gentoo;
	}
}

char getarg(const char *arg) {
	if (arg == NULL) return 0;
	if (arg[0] == '-') return arg[1];
	return 1;
}

int main(int argc, char *argv[]) {
	/* Command line arguments. */
	_Bool set_distro = 0;
	const char *colour = "36";

	char c;
	int i = 0;
	while ((c = getarg(argv[++i]))) {
		if (c == 'c') colour = argv[++i];
		else if (c == 'd') setdistro(argv[++i]);
	}

	/* Storage */
	int total_storage, used_storage, storage_percent;
	if (system("df --total | grep total > /home/basil/fetch/storage") >= 0) {
		FILE *fstorage = fopen("/home/basil/fetch/storage", "r");
		fscanf(fstorage, "%*s %d %d %*s %d", &total_storage, &used_storage, &storage_percent);
		fclose(fstorage);
	}

	total_storage = total_storage >> 20;
	used_storage = used_storage >> 20;
	int bar_percent = ((storage_percent * 12) / 100) + 1;
	for (int i = 0; i < bar_percent; i++) {
		memcpy(&storage_bar[i], "#", 1);
	}

	/* Print stuff. */
	printf("\e[%s;1m", colour);
	printf("%s", ascii_distro);
	printf("\e[43G"); // Cursor position.
	/* TODO: make cursor position and text colour dependant on selected ascii art. */
	printf("\e[%s;1m%s\e[0m\e[B\e[43G%s\e[B\e[43G", colour, "Simplefetch", "~~~~~~~~~~~"); // Title.
	//printf("", ); // Date.
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
	//printf(field_format, "Partition Table", partition_table);

	printf("\e[B\e[43G");
	printf("\e[30m███\e[31m███\e[32m███\e[33m███\e[34m███\e[35m███\e[36m███\e[37m███\e[B\e[43G");
	printf("\e[90m███\e[91m███\e[92m███\e[93m███\e[94m███\e[95m███\e[96m███\e[97m███\e[B\e[43G");

	printf("\e[4E");

	return 0;
}

/*
// Convert storage values to floats (do before "[var] = [var] >> 20").
float total_f = (float)total_storage, used_f = (float)used_storage;
// Divide by 2048 by subtracting 20 from the exponent.
 *(int *)&total_f -= 0x0a000000;
 *(int *)&used_f -= 0x0a000000;
 */

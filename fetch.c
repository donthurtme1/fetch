#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ascii.h"

static const char partition_table[] = "\e[B\e[47G\
sda                  [931.5 GiB]\e[B\e[47G\
├─sda1   /boot   [##-----------]  (15%)   - /     1 GiB\e[B\e[47G\
├─sda2   [SWAP]  [-------------]  ( 0%)   - /    16 GiB\e[B\e[47G\
├─sda3   /       [###----------]  (34%)  13 /    40 GiB\e[B\e[47G\
└─sda4   /home   [#------------]  ( 7%)  19 / 874.5 GiB";

static const char field_format[] = "\e[36;1m%s\e[0m: %s\e[B\e[43G";
static const char colour_block[] = "%s███";
static char bar_str[12] = "------------";

char getarg(const char *arg) {
	if (arg == NULL) return 0;
	if (arg[0] == '-') return arg[1];
	return 1;
}

int main(int argc, char *argv[]) {
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
		memcpy(&bar_str[i], "#", 1);
	}

	/* Print stuff. */
	printf(femboy_arch);
	printf("\e[19A\e[43G"); // Cursor position.
	printf("\e[36;1m%s\e[0m\e[B\e[43G%s\e[B\e[43G", "Simplefetch", "~~~~~~~~~~~"); // Title.
	//printf("", ); // Date.
	printf(field_format, "Distro", "Arch Linux");
	printf(field_format, "Window Manager", "dwl");
	printf(field_format, "Packages", "? - pacman");
	printf(field_format, "Terminal", "Alacritty");
	printf(field_format, "Terminal Font", "Hack Nerd Font");
	printf(field_format, "Shell", "bash 5.2.26");
	printf(field_format, "CPU", "AMD Ryzen 3 3200G @ 3.6 GHz");
	printf(field_format, "GPU", "AMD Radeon RX 6600");
	printf(field_format, "Memory", "16 GiB");
	printf("\e[36;1mStorage\e[0m: %d / %d GiB\e[53C\e[19D[%s] (%d%%)\e[B\e[43G", used_storage, total_storage, bar_str, storage_percent);
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

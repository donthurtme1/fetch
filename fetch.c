#include <stdio.h>

#define gotolc(line, column) printf("\e[%d;%dH", line, column)

static const char arch_ascii[] = "\e[36;1m\
                   -`\n\
                  .o+`\n\
                 `ooo/\n\
                `+oooo:\n\
               `+oooooo:\n\
               -+oooooo+:\n\
             `/:-:++oooo+:\n\
            `/++++/+++++++:\n\
           `/++++++++++++++:\n\
          `/+++ooooooooooooo/`\n\
         ./ooosssso++osssssso+`\n\
        .oossssso-````/ossssss+`\n\
       -osssssso.      :ssssssso.\n\
      :osssssss/        osssso+++.\n\
     /ossssssss/        +ssssooo/-\n\
   `/ossssso+/:-        -:/+osssso+-\n\
  `+sso+:-`                 `.-/+oso:\n\
 `++:.                           `-/+/\n\
 .`                                 `/\e[0m\n\n";

static const char femboy_arch[] = "\e[38;2;211;63;154m\
                   -`\n\
                  .o+`\n\e[38;2;229;160;198m\
                 `ooo/\n\
                `+oooo:\n\
               `+oooooo:\n\e[38;2;254;254;254m\
               -+oooooo+:\n\
             `/:-:++oooo+:\n\
            `/++++/+++++++:\n\e[38;2;61;200;247m\
           `/++++++++++++++:\n\
          `/+++ooooooooooooo/`\n\
         ./ooosssso++osssssso+`\n\e[38;2;254;254;254m\
        .oossssso-````/ossssss+`\n\
       -osssssso.      :ssssssso.\n\
      :osssssss/        osssso+++.\n\e[38;2;229;160;198m\
     /ossssssss/        +ssssooo/-\n\
   `/ossssso+/:-        -:/+osssso+-\n\
  `+sso+:-`                 `.-/+oso:\n\e[38;2;211;63;154m\
 `++:.                           `-/+/\n\
 .`                                 `/\e[0m\n\n";

static const char title[] = "\e[36;1mSimplefetch\e[0m";
static const char field_format[] = "\e[36;1m%s\e[0m: %s";
static const char colour_block[] = "%s███";

char getarg(const char *arg) {
	if (arg == NULL) return 0;
	if (arg[0] == '-') return arg[1];
	return 1;
}

int main(int argc, char *argv[]) {
	/*
	const char *ascii = arch_ascii;

	char c;
	int i = 0;
	while ((c = getarg(argv[++i]))) {
		if (c == 'g')
			ascii = femboy_arch;
	}
	*/

	printf(femboy_arch);

	/* Info */
	printf("\e[19A\e[43G"); /* Cursor position */
	printf("%s\e[E\e[43G", title);
	printf("~~~~~~~~~~~\e[E\e[43G");
	printf(field_format, "Distro", "Arch Linux\e[E\e[43G");
	printf(field_format, "Kernel", "?\e[E\e[43G");
	printf(field_format, "Window Manager", "dwl\e[E\e[43G");
	printf(field_format, "Packages", "?\e[E\e[43G");
	printf(field_format, "Terminal", "Alacritty\e[E\e[43G");
	printf(field_format, "Terminal Font", "Hack Nerd Font\e[E\e[43G");
	printf(field_format, "Shell", "bash 5.2.26\e[E\e[43G");
	printf(field_format, "CPU", "AMD Ryzen 3 3200G (4) @ 3.6 GHz\e[E\e[43G");
	printf(field_format, "GPU", "AMD Radeon RX 6600 XT\e[E\e[43G");
	printf(field_format, "Memory", "?\e[E\e[43G");
	printf(field_format, "Storage", "?\e[E\e[43G");

	printf("\e[E\e[43G");
	printf(colour_block, "\e[30m");
	printf(colour_block, "\e[31m");
	printf(colour_block, "\e[32m");
	printf(colour_block, "\e[33m");
	printf(colour_block, "\e[34m");
	printf(colour_block, "\e[35m");
	printf(colour_block, "\e[36m");
	printf(colour_block, "\e[37m");
	printf("\e[E\e[43G");
	printf(colour_block, "\e[90m");
	printf(colour_block, "\e[91m");
	printf(colour_block, "\e[92m");
	printf(colour_block, "\e[93m");
	printf(colour_block, "\e[94m");
	printf(colour_block, "\e[95m");
	printf(colour_block, "\e[96m");
	printf(colour_block, "\e[97m");

	printf("\e[4E");

	return 0;
}

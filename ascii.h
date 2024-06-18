static const char arch_ascii[] = "\
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
 .`                                 `/\e[0m\n\n\e[20A";

static const char simple_ascii_arch[] = "\
       .\e[B\e[8D\
      /#\\\e[B\e[9D\
     /###\\\e[B\e[10D\
    /p^###\\\e[B\e[11D\
   /##P^q##\\\e[B\e[12D\
  /##(   )##\\\e[B\e[13D\
 /###P   q#,^\\\e[B\e[14D\
/P^         ^q\\";

static const char simple_arch[] = "\
       -`       \
      .o+`      \
     -ooo:      \
    /+++++:     \
   .ossoosso`   \
  /sss-``/sso`  \
`/sss/    :sss- \
+oso:-    -:oso,\
/`            `/\
";

static const char simple_artix[] = "\
\e[6D\
           'A'\e[B\e[14D\
          'ooo'\e[B\e[15D\
         'ookxo'\e[B\e[16D\
         `ookxxo'\e[B\e[17D\
       '.   `ooko'\e[B\e[18D\
      'ooo`.   `oo'\e[B\e[19D\
     'ooxxxoo`.   `'\e[B\e[20D\
    'ookxxxkooo.`   .\e[B\e[21D\
   'ookxxkoo'`   .'oo'\e[B\e[22D\
  'ooxoo'`     .:ooxxo'\e[B\e[23D\
 'io'`             `'oo'\e[B\e[24D\
'`                     `'";

static const char space_invader[] = "\
  ▄     ▄\e[B\e[9D\
  ▄█▄▄▄█▄\e[B\e[9D\
▄██▄███▄██▄\e[B\e[11D\
█ █▀▀▀▀▀█ █\e[B\e[11D\
   ▀▀ ▀▀";

static const char space_invader_offset[] = "\
  ▗▖    ▗▖\e[B\e[10D\
  ▗▟▙▄▄▟▙▖\e[B\e[10D\
▗▟█▙▟██▙▟█▙▖\e[B\e[12D\
▐▌▐▛▀▀▀▀▜▌▐▌\e[B\e[12D\
   ▝▀▘▝▀▘";

static const char space_invader_even[] = "\
  ▀▄   ▄▀\e[B\e[9D\
 ▄█▀███▀█▄\e[B\e[10D\
█▀███████▀█\e[B\e[11D\
▀ ▀▄▄ ▄▄▀ ▀";

static const char squid[] = "\
      ▄▄▄\e[B\e[9D\
    ▄█████▄\e[B\e[11D\
  ▄█████████▄\e[B\e[13D\
▄███▀▀▀█▀▀▀███▄\e[B\e[15D\
▀▀█ █  ▄  █ █▀▀\e[B\e[15D\
   ▄▀▀▀▄▀▀▀▄\e[B\e[12D\
   █████████\e[B\e[12D\
   █▀█▀ ▀█▀█";

static const char jelly[] = "\
  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿             \
 ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿            \
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿           \
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿           \
   ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿              \
  ⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤             \
  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿             \
                             \
                             \
                             \
                             \
                             \
                             ";

static const char hires_jelly[] = "\
                  \e[B\e[9D\
    █▀             \e[B\e[11D\
▄█ █  ▀   ▝▘    █▄\e[B\e[13D\
▀█ ▀▄▄▄▙▟▄▙▄▄▞▀ █▀     \e[B\e[15D\
     ▐ ▌▐ ▌▐        \e[B\e[15D\
    ▂▔▔▔▔ ▚▂▔      \e[B\e[12D\
                  \e[B\e[12D\
                  ";

static const char gentoo_ascii[] = "\e[35;1m\
          -/oyddmdhs+:.\n\
       -o\e[37mdNMMMMMMMMNNmhy+\e[35m-`\n\
     -y\e[37mNMMMMMMMMMMMNNNmmdhy\e[35m+-\n\
   `o\e[37mmMMMMMMMMMMMMNmdmmmmddhhy\e[35m/`\n\
   om\e[37mMMMMMMMMMMMNhhyyyohmdddhhhd\e[35mo`\n\
  .y\e[37mdMMMMMMMMMMdhs++so/smdddhhhhdm\e[35m+`\n\
   oy\e[37mhdmNMMMMMMMNdyooydmddddhhhhyhN\e[35md.\n\
    :o\e[37myhhdNNMMMMMMMNNNmmdddhhhhhyym\e[35mMh\n\
      .:\e[37m+sydNMMMMMNNNmmmdddhhhhhhmM\e[35mmy\n\
         /m\e[37mMMMMMMNNNmmmdddhhhhhmMNh\e[35ms:\n\
      `o\e[37mNMMMMMMMNNNmmmddddhhdmMNhs+\e[35m`\n\
    `s\e[37mNMMMMMMMMNNNmmmdddddmNMmhs\e[35m/.\n\
   /N\e[37mMMMMMMMMNNNNmmmdddmNMNdso\e[35m:`\n\
  +M\e[37mMMMMMMNNNNNmmmmdmNMNdso\e[35m/-\n\
  yM\e[37mMNNNNNNNmmmmmNNMmhs+/\e[35m-`\n\
  /h\e[37mMMNNNNNNNNMNdhs++/\e[35m-`\n\
  `/\e[37mohdmmddhys+++/:\e[35m.`\n\
    `-//////:--.\e[0m\n\n\e[19A";

/* Gay! */
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
 .`                                 `/\e[0m\n\n\e[20A";

static const char femboy_gentoo[] = "\e[38;2;211;63;154m\
          -/oyddmdhs+:.\n\
       -odNMMMMMMMMNNmhy+-`\n\e[38;2;229;160;198m\
     -yNMMMMMMMMMMMNNNmmdhy+-\n\
   `omMMMMMMMMMMMMNmdmmmmddhhy/`\n\
   omMMMMMMMMMMMNhhyyyohmdddhhhdo`\n\e[38;2;254;254;254m\
  .ydMMMMMMMMMMdhs++so/smdddhhhhdm+`\n\
   oyhdmNMMMMMMMNdyooydmddddhhhhyhNd.\n\
    :oyhhdNNMMMMMMMNNNmmdddhhhhhyymMh\n\e[38;2;61;200;247m\
      .:+sydNMMMMMNNNmmmdddhhhhhhmMmy\n\
         /mMMMMMMNNNmmmdddhhhhhmMNhs:\n\e[38;2;254;254;254m\
      `oNMMMMMMMNNNmmmddddhhdmMNhs+`\n\
    `sNMMMMMMMMNNNmmmdddddmNMmhs/.\n\
   /NMMMMMMMMNNNNmmmdddmNMNdso:`\n\e[38;2;229;160;198m\
  +MMMMMMMNNNNNmmmmdmNMNdso/-\n\
  yMMNNNNNNNmmmmmNNMmhs+/-`\n\
  /hMMNNNNNNNNMNdhs++/-`\n\e[38;2;211;63;154m\
  `/ohdmmddhys+++/:.`\n\
    `-//////:--.\e[0m\n\n\e[19A";

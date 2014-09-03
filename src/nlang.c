#include "nlang.h"

char* g_filename;

void print_usage() {
  puts("Usage: nlang -[h] --[help] [FILENAME]\n");
}

void parse_options(int argc, char** argv) {
  int c;
  int digit_optind = 0;

  while (1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
      {"help",    0, 0,  'h' },
      {0,         0, 0,  0 }
    };

    c = getopt_long(argc, argv, "",
      long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {
    case 0:
      printf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s", optarg);
      printf("\n");
      break;

    case '?':
      break;

    default:
      printf("?? getopt returned character code 0%o ??\n", c);
    }
  }

  if (optind < argc) {
    g_filename = argv[optind];
  }

}

int main(int argc, char** argv) {
  parse_options(argc, argv);
  lex_from_file(g_filename);
  return 0;
}

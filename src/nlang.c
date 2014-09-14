#include "nlang.h"

char* g_filename;

void print_usage() {
  puts("Usage: nlang -[h] --[help] [FILENAME]\n");
}

int main(int argc, char** argv) {
  g_filename = argv[1];
  lex_from_file(g_filename);
  return 0;
}

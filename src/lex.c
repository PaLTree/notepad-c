#include "nlang.h"

void lex_from_file(const char* filename) {
  INIT_PTR(FILE, fp)
  char line[256] = {'\0'};
  fp = fopen(filename, "r");
  if(fp == NULL) {
    perror(filename);
    _exit(-1);
  }
  while(fgets(line, 256, fp) != NULL) {
    printf("%s", line);
  }
  fclose(fp);
}

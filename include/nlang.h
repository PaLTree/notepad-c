#ifndef __NLANG_H__
#define __NLANG_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>

#include "LinkedList.h"

/* lex.c */
void lex_from_file(const char*);

/* parser.c */
void parse_from_file(const char*);

#endif //__NLANG_H__

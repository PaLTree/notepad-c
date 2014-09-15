#ifndef __NLANG_H__
#  define __NLANG_H__

#  include <stdio.h>
#  include <string.h>
#  include <stdlib.h>
#  include <stdbool.h>
#  include <unistd.h>
#  include <getopt.h>

#  include "LinkedList.h"

/* lex.c */
void lex_from_file(const char*);

/* parser.c */
void parse_from_file(const char*);

typedef enum {
  T_OPERATOR, 
  T_KEYWORD, 
  T_LITERAL, 
} TokenKind;

typedef enum {
  ACC_PUBLIC,
  ACC_PROTECTED,
  ACC_PRIVATE
} AccessModifiers;

typedef enum {
  M_METHOD,
  M_FIELD
} MemberKind;

typedef struct _field {
  Data value;
} Field;

typedef struct _method {
  LinkedList bytecode;
} Method;

typedef struct _classmember {
  char *name;
  AccessModifiers am;
  MemberKind type;
  union {
    Field f;
    Method m;
  } u;
} ClassMember;

typedef struct _class {
  char* fqdn;
  AccessModifiers am;
  ClassMember **static_members;
  ClassMember **members;
} Class;

typedef struct _object {
  char* unique_name;
  Class class; 
} Object;

#  define INIT_PTR(type, var) type *var = NULL;
#  define free_s(ptr) do { if(ptr != NULL) {free(ptr);} } while(0);
#  define malloc_s(ptr, type, size) do { ptr = (type *) malloc(sizeof(type) * size); memset(ptr, '\0', sizeof(type) * size); } while(0);
#    ifndef NDEBUG
#      define debug_log(message, values...) do{ \
    fprintf(stderr, "FILE: %s\n", __FILE__); \
    fprintf(stderr, "LINE: %d\n", __LINE__); \
    fprintf(stderr, "FUNCTION: %s\n", __FUNCTION__); \
    fprintf(stderr, message, values); \
  } while(0);
#    else
#      define debug_log(x) 
#    endif
#endif //__NLANG_H__

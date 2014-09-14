#include "nlang.h"

char* g_filename;

void print_usage() {
  puts("Usage: nlang -[h] --[help] [FILENAME]\n");
}

void eachfunc(Node *node) {
	printf("%d: %s\n", node->index, (char*)node->data);
}

int main(int argc, char** argv) {
  //g_filename = argv[1];
  //lex_from_file(g_filename);
  LinkedList list;
  list = linkedlist_initialize();
  linkedlist_add(list, "paralleltree");
  linkedlist_add(list, "kb10uy");
  linkedlist_add(list, "noko_k");
  linkedlist_add(list, "snovxn");
  linkedlist_add(list, "09sanumi");
  linkedlist_add(list, "n_6g");
  linkedlist_add(list, "nanase_coder");
  linkedlist_add(list, "m1zu44");
  linkedlist_each_function(list, eachfunc);
  linkedlist_free(list);
  return 0;
}

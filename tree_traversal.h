#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

#include "node.h"

// Functions for traversals
void print_pre_order(std::ofstream &, Node *);
void print_in_order(std::ofstream &, Node *);
void print_post_order(std::ofstream &, Node *);

// Print all node words
void print_words(std::ofstream &file,std::set<std::string> words);

#endif

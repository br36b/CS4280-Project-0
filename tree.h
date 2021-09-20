#ifndef TREE_H

#include "node.h"

/* Functions Have the following functions/methods minimum (the types and arguments are up to you, the names are required as given)
buildTree()
printInorder()
printPreorder()
printPostorder() */

Node *build_tree(std::string);
void print_in_order(std::string, Node*);
void print_pre_order(std::string, Node*);
void print_post_order(std::string, Node*);

struct Node *new_node(char, std::string, int);
struct Node *insert_node(struct Node *, char, std::string);
struct Node *minValueNode(struct Node *Node);
struct Node *deleteNode(struct Node *root, int key);

#endif

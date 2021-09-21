#ifndef TREE_H

#include "node.h"

/* Functions Have the following functions/methods minimum (the types and arguments are up to you, the names are required as given)
buildTree()
printInorder()
printPreorder()
printPostorder() */

// print functions moved to traversal files now

Node *build_tree(std::string);

struct Node *new_node(char, std::string, int);
struct Node *insert_node(struct Node *, char, std::string);

// Unneeded ones from link in .cpp
/* struct Node *minValueNode(struct Node *Node); */
/* struct Node *deleteNode(struct Node *root, int key); */

#endif

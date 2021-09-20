#ifndef NODE_H
#define NODE_H

// Only here because they are used in the node vars
#include <string>
#include <set>

// Modified off https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
struct Node {
  // Key will be letter
  char letter;
  int depth;

  // Use vector to avoid having to resize arrays
  std::set<std::string> words;

  // Binary Tree
  struct Node *left;
  struct Node *right;
  struct Node *next;
};


#endif

#ifndef NODE_H
#define NODE_H

// Only here because they are used in the node vars
#include <vector>
#include <string>

// Modified off https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
struct Node {
  // Change key to letter to hold top level
  char letter;

  std::vector<std::string> words;

  struct Node *left;
  struct Node *right;
};

#endif

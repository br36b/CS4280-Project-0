#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "tree.h"

Node * start = NULL;

Node *build_tree(std::string filename) {

  // Temporarily hold the first char/int conversion
  char letter;
  std::string temp_input;

  std::ifstream in_stream(filename.c_str());

  std::cout << "Building Tree." << std::endl;

  // Make sure file can open
  if (in_stream.fail()) {
    std::cout << "Unable to open file to create tree: " << filename << std::endl;

    return NULL;
  }
  // Make sure file has contents
  else {
    std::cout << "Checking contents" << std::endl;

    if (in_stream.peek() == std::ifstream::traits_type::eof()) {
      std::cout << "Not enough data to form tree." << std::endl;
      return NULL;
    }
  }

  std::cout << "Beginning tree file read." << std::endl;
  // If it gets here than it read file
  while (in_stream >> temp_input) {
    // Swap to .at() for compiler here
    letter = temp_input.at(0);

    /* std::cout << " LETTER: " << letter << " Word: " << temp_input << std::endl;; */
    insert_node(start, letter, temp_input);
  }

  return start;
}

// Reusing node creation from https://www.programiz.com/dsa/binary-search-tree
// Slightly modifying for this project

// Create a Node
struct Node *new_node(char letter, std::string word, int depth) {
  // MUST convert to new standard to avoid segfault
  // Set was probably eating more space than allocated at start
  struct Node *temp_node = new Node;

  temp_node->letter = letter;
  temp_node->depth = depth;

  temp_node->left = temp_node->right = temp_node->next= NULL;

  // Make sure enough space for a set for future reference
  temp_node->words.insert(word);

  return temp_node;
}

// Insert a Node
Node *insert_node(Node *temp, char letter, std::string word) {
  /* std::cout << "Inserting Node" << std::endl; */

  // Return a new node if the tree is empty
  if (start == NULL) {
    start = new_node(letter, word, 0);

    start->next = start;
  }
  // Current letter is head node
  // Add the word to the node's word list
  else if (temp->letter == letter) {
    temp->words.insert(word);
  }
  // Letter is greater therefore on right
  else if (temp->letter < letter) {
    // If empty then we need a new node
    if (temp->right == NULL) {
      temp->right = new_node(letter, word, temp->depth + 1);
    }
    // Check if the node matches letter
    else if (temp->right->letter == letter) {
      temp->right->words.insert(word);
    }
    // Otherwise reuse process, create a node at that point
    else {
      insert_node(temp->right, letter, word);
    }
  }
  // Letter is less than node
  else if (temp->letter > letter) {
    // If empty then we need a new node
    if (temp->left == NULL) {
      temp->left = new_node(letter, word, temp->depth + 1);
    }
    // Check if the node matches letter
    else if (temp->left->letter == letter) {
      temp->left->words.insert(word);
    }
    // Otherwise reuse process, create a node at that point
    else {
      insert_node(temp->left, letter, word);
    }
  }
  else {
    std::cout << "Double Check." << std::endl;
  }

  /* // Traverse to the right place and insert the node */
  /* if (letter < temp->letter) */
  /*   temp->left = insert_node(temp->left, letter); */
  /* else */
  /*   temp->right = insert_node(temp->right, letter); */

  return temp;
}


// Extra code from source link above
/* // Find the inorder successor */
/* struct Node *minValueNode(struct Node *Node) { */
/*   struct Node *current = Node; */

/*   // Find the leftmost leaf */
/*   while (current && current->left != NULL) */
/*     current = current->left; */

/*   return current; */
/* } */

/* // Deleting a Node */
/* struct Node *deleteNode(struct Node *root, int key) { */
/*   // Return if the tree is empty */
/*   if (root == NULL) return root; */

/*   // Find the Node to be deleted */
/*   if (key < root->letter) */
/*     root->left = deleteNode(root->left, key); */
/*   else if (key > root->letter) */
/*     root->right = deleteNode(root->right, key); */
/*   else { */
/*     // If the Node is with only one child or no child */
/*     if (root->left == NULL) { */
/*       struct Node *temp = root->right; */
/*       free(root); */
/*       return temp; */
/*     } else if (root->right == NULL) { */
/*       struct Node *temp = root->left; */
/*       free(root); */
/*       return temp; */
/*     } */

/*     // If the Node has two children */
/*     struct Node *temp = minValueNode(root->right); */

/*     // Place the inorder successor in position of the Node to be deleted */
/*     root->letter = temp->letter; */

/*     // Delete the inorder successor */
/*     root->right = deleteNode(root->right, temp->letter); */
/*   } */
/*   return root; */
/* } */

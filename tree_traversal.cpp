#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>

#include "tree_traversal.h"

// Each of the traversals will write them to their respective file
void print_pre_order(std::ofstream &file, Node *root) {
  if (root != NULL) {
    // Indent by 2x depth of node
    std::string indent = std::string(root->depth * 2, ' ');

    // Traverse root, display first letter of node strings
    file << indent << "D"<< root->depth << " - " << root->letter << ": ";
    std::cout << indent << "D"<< root->depth << " - " << root->letter << ": ";

    // Followed by list of strings from node set
    print_words(file, root->words);

    // Traverse left
    print_pre_order(file, root->left);

    // Traverse right
    print_pre_order(file, root->right);
  }
}

// In order just swapped the order of root
void print_in_order(std::ofstream &file, Node *root) {
  if (root != NULL) {
    // Traverse left
    print_in_order(file, root->left);

    // Indent by 2x depth of node
    std::string indent = std::string(root->depth * 2, ' ');

    // Traverse root, display first letter of node strings
    file << indent << "D"<< root->depth << " - " << root->letter << ": ";
    std::cout << indent << "D"<< root->depth << " - " << root->letter << ": ";

    // Followed by list of strings from node set
    print_words(file, root->words);

    // Traverse right
    print_in_order(file, root->right);
  }
}

// Post order just swapped the order of root
void print_post_order(std::ofstream &file, Node *root) {
  if (root != NULL) {
    // Traverse left
    print_post_order(file, root->left);

    // Traverse right
    print_post_order(file, root->right);

    // Indent by 2x depth of node
    std::string indent = std::string(root->depth * 2, ' ');

    // Traverse root, display first letter of node strings
    file << indent << "D"<< root->depth << " - " << root->letter << ": ";
    std::cout << indent << "D"<< root->depth << " - " << root->letter << ": ";

    // Followed by list of strings from node set
    print_words(file, root->words);
  }
}

// Print all the words inside of node for that letter
// Will also output them to a file
void print_words(std::ofstream &file,std::set<std::string> words) {
  /* std::cout << "Printing Words" << std::endl; */
  // convert from unsigned long int to int
  // Iterate every word to output
  for (std::string const& word: words) {
    std::cout << word << ' ';
    file << word << ' ';
  }

  std::cout << std::endl;
  file << std::endl;
}

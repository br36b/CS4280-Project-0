/*
 * Name: Bryan Rojas
 * CS4280
 * Date: 9/20/21
 * Purpose: Build a BST from file/keyboard input and traverse them into output
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>

#include "node.h"
#include "tree.h"
#include "tree_traversal.h"

void create_file_from_input(std::string);
void attempt_to_open_file(std::ofstream &, std::string);

int main(int argc, char *argv[]) {
  // String constants for file names/ending
  const std::string FILE_ENDING = ".fl2021";
  const std::string DEFAULT_FILE = "temp_dat123";

  const std::string FILE_PREORDER_ENDING = ".preorder";
  const std::string FILE_INORDER_ENDING = ".inorder";
  const std::string FILE_POSTORDER_ENDING = ".postorder";

  std::string filename;

  // Before doing anything make sure no excess params
  if (argc > 2) {
    std::cout << "Excess arguments given. Exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
  // No input file, read from keyboard
  else if (argc == 1) {
    std::cout << "No file provided. Taking input (CTRL-D to end): " << std::endl;

    // Set default file and create it with data inputted
    filename = DEFAULT_FILE;
    create_file_from_input(filename + FILE_ENDING);
  }
  // Input file provided
  else if (argc == 2) {
    std::cout << "File provided. Verifying.";

    // Take the arg and store it
    filename = argv[1];

    int file_length = filename.length();

    // If it has an extension
    // .fl2021 will be 7 chars + 1 letter
    // If it has a dot, then it is a wrong length for an extension
    // Given that 8 will be the minimum
    if (filename.find(".") != std::string::npos) {
      /* std::cout << filename << " " << file_length << std::endl; */

      // By this point it has a dot and should be at least 8 chars
      if (filename.find("fl2021") != std::string::npos) {
        if (file_length < 8) {
          std::cout << "File is missing a name for this extension." << std::endl;
          exit(EXIT_FAILURE);
        }
      }
      // Otherwise it is an incorrect format that does not contain it
      else {
        std::cout << "File is an incorrect format. Requires *.fl2021 if provided." << std::endl;
        exit(EXIT_FAILURE);
      }

      // Substring removal of file ending since it is implied in program
      size_t last_index = filename.find_last_of(".");
      filename = filename.substr(0, last_index);
    }
    // Otherwise it doesn't contain any file ending, so it is implied to add the extension
    // Which will work out on the build_tree() process
  }

  // Hold the tree generated from the file inputs
  Node *root = build_tree(filename + FILE_ENDING);

  // Check to see if anything was added, failure if no data was passed
  if (root == NULL) {
    std::cout << "Data was empty. Exiting." << std::endl;
    exit(EXIT_FAILURE);
  }

  // If keyboard input, produce output.* files
  if (filename == DEFAULT_FILE) {
    filename = "output";
  }

  // Hold a file for outputting into respective ending locations
  std::ofstream temp_stream;

  // For each of the traversals
  // Verify file can open
  // Print each item according to spec
  // Close that file when done
  // Move on to the next set
  std::cout << "\nOutputting Pre-Order Traversal" << std::endl;
  attempt_to_open_file(temp_stream, filename + FILE_PREORDER_ENDING);
  print_pre_order(temp_stream, root);
  temp_stream.close();

  std::cout << "\nOutputting In-Order Traversal" << std::endl;
  attempt_to_open_file(temp_stream, filename + FILE_INORDER_ENDING);
  print_in_order(temp_stream, root);
  temp_stream.close();

  std::cout << "\nOutputting Post-Order Traversal" << std::endl;
  attempt_to_open_file(temp_stream, filename + FILE_POSTORDER_ENDING);
  print_post_order(temp_stream, root);
  temp_stream.close();

  // Delete the temp file if it exists
  std::string default_file_name = DEFAULT_FILE + FILE_ENDING;
  std::remove(default_file_name.c_str());

  // Just for exit formatting
  std::cout << std::endl;

  return 0;
}


// Will generate a temp_file in the directory.
void create_file_from_input(std::string filename) {
  // Take and store some input temporarily
  std::ofstream out_stream;
  attempt_to_open_file(out_stream, filename);

  std::string input;

  while (std::cin >> input) {
    // std::cout << "ADDING" << input << std::endl;

    // Write to file, separate for breaking
    out_stream << input << " ";
  }

  // Close the file after input is done
  out_stream.close();
}

// Helper to verify and store the pointer of a file
void attempt_to_open_file(std::ofstream &temp, std::string filename) {
  // Attempt to open path given
  temp.open(filename.c_str());

  // Exit if no file could be created for output
  if (temp.fail()) {
    std::cout << "Failed to create a file for data output. Exiting." << std::endl;

    exit(EXIT_FAILURE);
  }
}

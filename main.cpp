#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "node.h"
#include "tree.h"

void create_file_from_input(std::string);

int main(int argc, char *argv[]) {
  const std::string FILE_ENDING = ".fl2021";

  std::string filename;

  // Before doing anything make sure no excess params
  if (argc > 2) {
    std::cout << "Excess arguments given. Exiting" << std::endl;
    exit(EXIT_FAILURE);
  }
  // No input file, read from keyboard
  else if (argc == 1) {
    std::cout << "No file provided. Taking input (CTRL-D to end): " << std::endl;

    filename = "temp_data" + FILE_ENDING;
    create_file_from_input(filename);
  // TODO: CONFIRM VALID FILE
  // After getting/creating file, use it to build tree
  }
  // Input file provided
  else if (argc == 2) {
    std::cout << "File provided. Verifying.";

    // Take the arg and store it
    filename = argv[1];

    filename += FILE_ENDING;

    // TODO: VERIFY FILE ENDING
    // TODO: CONFIRM VALID FILE
    // After getting/creating file, use it to build tree
  }

  // TODO: Print traversals at the end
  Node *root = build_tree(filename);

  if (root == NULL) {
    std::cout << "Data was empty. Exiting." << std::endl;
    exit(EXIT_FAILURE);
  }

  /* print_in_order(filename, root); */

  return 0;
}


// Will generate a temp_file in the directory.
void create_file_from_input(std::string filename) {
  // Take and store some input temporarily
  std::ofstream out_stream;

  std::string input;

  // Exit out if no file could be created
  if (out_stream.fail()) {
    std::cout << "Failed to create temp data file. Exiting." << std::endl;
    exit(EXIT_FAILURE);
  }

  // Just create a temp_file to store inputs
  out_stream.open(filename.c_str());

  while (std::cin >> input) {
    // std::cout << "ADDING" << input << std::endl;

    // Write to file, separate for breaking
    out_stream << input << " ";
  }

  // Close the file after input is done
  out_stream.close();
}

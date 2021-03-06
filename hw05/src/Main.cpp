#include <stdexcept>
#include <iostream>
#include "Huffman.h"
using namespace std;
using namespace hw05;

/**
 * @namespace hw05 Binary trees and the Huffman
 * coding algorithm.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for testing binary trees and
 * the Huffman coding algorithm.
 * @return The exit status.  Normal status is 0.
 */
int main() {
  try {

    // This part should produce the same output as
    // the main program of Homework #4.

    // Create a binary tree.

    const BinaryTree a("A", 4);
    const BinaryTree b("B", 2);
    const BinaryTree c("C", 2);
    const BinaryTree d("D", 2);
    const BinaryTree e("E", 7);
    const BinaryTree bc(b, c);
    const BinaryTree ad(a, d);
    const BinaryTree abcd(ad, bc);
    const BinaryTree top(abcd, e);

    // Print the tree.

    top.printTree(cout);
    cout << endl;

    // Look up some text in the binary tree.

    cout << top.decode("ADDDAADD") << endl;

    // This part tests the Huffman coding algorithm.

    // Create a Huffman object and populate it.

    Huffman huffman;
    huffman.addTree(BinaryTree("A", 6));
    huffman.addTree(BinaryTree("B", 5));
    huffman.addTree(BinaryTree("C", 3));
    huffman.addTree(BinaryTree("D", 4));
    huffman.addTree(BinaryTree("E", 8));

    // Apply the Huffman coding algorithm.

    BinaryTree decoder(huffman.applyHuffman());

    // Print the Huffman tree.
    // This should be "((E (D C)) (A B))"

    decoder.printTree(cout);
    cout << endl;
  } catch (const domain_error& error) {

    // Show the error.

    cout << error.what() << endl;
    return 1;
  }

  // Normal return

  return 0;
}

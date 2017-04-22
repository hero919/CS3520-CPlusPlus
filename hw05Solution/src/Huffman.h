#ifndef HW05_HUFFMAN_H
#define HW05_HUFFMAN_H

#include <string>
#include "BinaryTree.h"

namespace hw05 {

/**
 * The Huffman coding algorithm.
 *
 * @author Ken Baclawski
 */
class Huffman {
public:
  /**
   * Add a binary tree to the list of binary trees.
   */
  void addTree(/** The new tree to add to the list. */
	       const BinaryTree& tree) noexcept;

  /**
   * Apply the Huffman algorithm.
   * @throw domain_error if the list of binary
   * trees is empty.
   */
  BinaryTree applyHuffman();

private:
  /** The list of binary trees. */
  std::vector<BinaryTree> trees_;
};

}

#endif

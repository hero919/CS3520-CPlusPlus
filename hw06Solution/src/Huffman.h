#ifndef HW06_HUFFMAN_H
#define HW06_HUFFMAN_H

#include <string>
#include "BinaryTree.h"

namespace hw06 {

/**
 * The Huffman coding algorithm.
 *
 * @author Ken Baclawski
 */
class Huffman {
public:
  /**
   * Apply the Huffman algorithm on training data.
   * @throw domain_error if the training data is
   * not sufficient for a Huffman decoder.
   */
  Huffman(/** The training data. */
	  const std::string& trainingData);

  /**
   * Decode some encoded data.
   * @return The decoded data.
   */
  std::string decode(/** The encoded data. */
		     const std::string& encodedData) const;
private:
  /** The binary tree for the Huffman coding. */
  BinaryTree coder_;
};

}

#endif

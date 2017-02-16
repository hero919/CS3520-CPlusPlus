#ifndef HW05_BINARYTREE_H
#define HW05_BINARYTREE_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

namespace hw05 {

/**
 * A binary tree.  In this binary tree, only
 * leaves have values, and all internal nodes have
 * exactly two child nodes.  This structure is
 * also known as a Lisp list.
 *
 * @author Ken Baclawski
 */
class BinaryTree {
public:
  /**
   * Construct a leaf node.  The value is a string
   * (text) and a number (weight).
   */
  BinaryTree(/** The text of the node. */ const std::string& text,
	     /** The numeric weight of the node. */ int weight);

  /**
   * Construct an internal node.
   */
  BinaryTree(/** The left child. */ const BinaryTree& left,
	     /** The right child. */ const BinaryTree& right);

  /**
   * Decode a path.  The path parameter is copied
   * because it could be modified by the method.
   * @return The decoded path.
   */
  std::string decode(/** The path to be decoded. */
		     std::string path) const;

  /**
   * Traverse the binary tree in depth-first
   * search order.
   */
  void traverse(/** The function to apply to every leaf node. */
                const std::function<void(const std::string& text, double weight)>& function)
		const noexcept;

  /**
   * Print the binary tree to an output stream.
   */
  void printTree(/** The output stream where the tree is to be printed. */
                 std::ostream& out) const noexcept;

private:
  /** The text value of a leaf node. */
  std::string text_;
  /** The numeric value of a leaf node. */
  int weight_ = 0;
  /** The children of the node. */
  std::vector<BinaryTree> children_;

  /**
   * The label of the node specified by a path.
   * The directions are L and R (left and right).
   * One can also use A and D (from the notation
   * for lisp lists).  In lisp, the function cadr
   * is the node obtained by applying car and cdr.
   * In terms of binary trees, this means get the
   * left child and then the right child.  In this
   * function, this could be specified using the
   * string "AD", or "LR", or "AR", and so on.
   * @return The text of the leaf node specified
   * by the path.  If the path ends before reaching
   * a leaf node, then a blank string is returned.
   * @throws domain_error if the path is invalid.
   */
  std::string get
  (/**
    * An iterator specifying where to start the path.
    * This iterator is incremented as each letter in
    * the path is used.
    */
   std::string::iterator& start,
   /** The iterator marking the end of the string. */
   const std::string::iterator& end) const;
};

}

#endif

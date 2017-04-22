#ifndef HW06_BINARYTREE_H
#define HW06_BINARYTREE_H

#include <string>
#include <vector>

namespace hw06 {

/**
 * A binary tree.  In this binary tree, all nodes
 * have weights but only leaves have text values.
 * The weight of an internal node is the sum of
 * the weights of its child nodes.
 *
 * @author Ken Baclawski
 */
class BinaryTree {
public:
  /**
   * The default binary tree.  It has one leaf
   * node with the default text and weight.
   */
  BinaryTree() = default;

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
   * @throws domain_error if the path is invalid.
   */
  std::string decode(/** The path to be decoded. */
		     std::string path) const;

  /**
   * Get the weight of this tree.
   * @return the weight of the tree.  This is
   * equal to the sum of the weights of the leaf
   * nodes.
   */
  double getWeight() const noexcept;

  /**
   * Represent the tree as a string.
   * @return The tree using a Lisp-like format.
   */
  std::string toString() const noexcept;

private:
  /** The text value of a leaf node. */
  std::string text_;
  /** The numeric value of a node. */
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

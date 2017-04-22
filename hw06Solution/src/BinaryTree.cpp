#include <stdexcept>
#include <iostream>
#include "BinaryTree.h"
using namespace std;
using namespace hw06;

BinaryTree::BinaryTree(const string& text, int weight)
  : text_(text), weight_(weight) {}

BinaryTree::BinaryTree(const BinaryTree& left, const BinaryTree& right)
  : children_{left, right} {
  weight_ = children_.at(0).weight_ + children_.at(1).weight_;
}

string BinaryTree::decode(string path) const {

  // Check for the degenerate case

  if (children_.empty()) {
    throw domain_error("Attempt to decode using a binary tree with only one node");
  }

  // Scan the string to decode it.

  string result;
  for (string::iterator iter = path.begin(); iter != path.end(); ) {
    result += get(iter, path.end());
  }
  return result;
}

double BinaryTree::getWeight() const noexcept {
  return weight_;
}

string BinaryTree::get(string::iterator& start, const string::iterator& end) const {

  // If this is a leaf node, then return the text.

  if (children_.empty()) {
    return text_;
  }

  // If the end of the path was reached before a
  // leaf node, then the text is empty.

  if (start >= end) {
    return "";
  }

  // Otherwise, go in the indicated direction and
  // recurse.

  char direction = *start;
  ++start;
  if (direction == 'A' || direction == 'L') {
    return children_.at(0).get(start, end);
  } else if (direction == 'D' || direction == 'R') {
    return children_.at(1).get(start, end);
  }

  // If the direction is not valid, throw an exception.

  throw domain_error("Invalid path");
}

string BinaryTree::toString() const noexcept {
  if (children_.empty()) {

    // This is a leaf node, so show the text.

    return text_;
  } else {

    // This is an internal node, so show the child
    // nodes recursively.

    return "(" + children_.at(0).toString() + " " + children_.at(1).toString() + ")";
  }
}

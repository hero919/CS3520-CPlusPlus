#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "BinaryTree.h"
using namespace std;
using namespace hw04;

BinaryTree::BinaryTree(const string& text, int weight)
  : text_(text), weight_(weight) {}

BinaryTree::BinaryTree(const BinaryTree& left, const BinaryTree& right)
  : children_{left, right} {}

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

void BinaryTree::printTree(ostream& out) const noexcept {
  if (children_.empty()) {

    // This is a leaf node, so show the text.

    out << text_;
  } else {

    // This is an internal node, so show the child
    // nodes recursively.

    out << "(";
    children_.at(0).printTree(out);
    out << " ";
    children_.at(1).printTree(out);
    out << ")";
  }
}

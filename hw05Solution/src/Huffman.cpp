#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Huffman.h"
using namespace std;
using namespace hw05;

void Huffman::addTree(const BinaryTree& tree) noexcept {
  trees_.push_back(tree);
}

BinaryTree Huffman::applyHuffman() {

  // Check for the degenerate case

  if (trees_.empty()) {
    throw domain_error("Attempt to apply the Huffman coding algorithm to an empty list of trees");
  }

  // Construct a lambda expression for computing
  // the total weight of a binary tree.

  double totalWeight = 0.0;
  auto computeWeight = [&](const string& text, double weight) {
    totalWeight += weight;
  };

  // Construct a lambda expression for determining
  // whether two binary trees are in reverse order
  // by weight.

  auto compare = [&](const BinaryTree& a, const BinaryTree& b) {
    totalWeight = 0.0;
    a.traverse(computeWeight);
    double weightOfA = totalWeight;
    totalWeight = 0.0;
    b.traverse(computeWeight);
    double weightOfB = totalWeight;
    return weightOfA > weightOfB;
  };

  // Apply the algorithm until the number of trees
  // is equal to 1.

  while (trees_.size() > 1) {

    // Sort in reverse order by weight.

    sort(trees_.begin(), trees_.end(), compare);

    // Remove the last two binary trees in the list.

    auto ultimate = trees_.back();
    trees_.pop_back();
    auto penultimate = trees_.back();
    trees_.pop_back();

    // Combine the two binary trees.

    BinaryTree combine(penultimate, ultimate);

    // Add the combined binary tree to the list.

    trees_.push_back(combine);
  }

  // There is now exactly one tree in the list.
  // This tree is the end result of the Huffman
  // coding algorithm.

  return trees_.back();
}

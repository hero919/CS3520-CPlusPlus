#include <map>
#include <set>
#include <iostream>
#include "Huffman.h"

using namespace std;
using namespace hw06;

Huffman::Huffman(const string& trainingData) {

  // Compute the frequencies of the letters

  map<char, int> frequencies;
  for (unsigned int i = 0; i < trainingData.length(); ++i) {
    char c = trainingData.at(i);

    // If the character is not in the map, then add it.

    if (frequencies.count(c) == 0) {
      frequencies.insert( { c, 0 } );
    }

    // Increment the frequency for this character.

    frequencies.at(c)++;
  }

  // Construct a lambda expression for determining
  // whether two binary trees are in order by
  // weight.

  auto compare = [](const BinaryTree& a, const BinaryTree& b) {
    if (a.getWeight() < b.getWeight()) {
      return true;
    } else if (a.getWeight() > b.getWeight()) {
      return false;
    } else {
      return a.toString() < b.toString();
    }
  };

  // Construct the multiset of trees.  It must be a
  // multiset because there may be two trees with
  // the same weight

  multiset<BinaryTree, decltype(compare)> trees(compare);
  for (auto frequency : frequencies) {
    trees.insert(BinaryTree(string(1, frequency.first), frequency.second));
  }
  if (trees.size() <= 1) {
    throw domain_error("Attempt to apply the Huffman algorithm with too few letters");
  }

  // Apply the algorithm until the number of trees
  // is equal to 1.

  while (trees.size() > 1) {

    // Remove the first two (lowest weight) binary
    // trees in the list.

    auto iter = trees.begin();
    auto first = *iter;
    ++iter;
    auto second = *iter;
    ++iter;
    trees.erase(trees.begin(), iter);

    // Combine the two binary trees.

    BinaryTree combine(first, second);

    // Add the combined binary tree to the list.

    trees.insert(combine);
  }

  // There is now exactly one tree in the list.
  // This tree is the end result of the Huffman
  // coding algorithm.

  coder_ = *(trees.begin());

  cout << coder_.toString() << endl;
}

string Huffman::decode(const string& encodedData) const {
  return coder_.decode(encodedData);
}

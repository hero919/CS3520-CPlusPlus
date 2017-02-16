/*
 * Huffman.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: zeqingzhang
 */
#include "Huffman.h"
#include <algorithm>
#include <functional>
using namespace std;
using namespace hw05;

void Huffman::addTree(const BinaryTree& tree) noexcept{
		//Each time add the new tree, push it to the end of the tree vector
		trees_.push_back(tree);
}


BinaryTree Huffman::applyHuffman(){
	//If the given tree is a leaf, throw an exception
	if(trees_.size() == 0){
		throw domain_error("The size of the tree array is 0!");
	}

	//If the trees size is one, return that one, because that is the result.
	if(trees_.size() == 1){
		return trees_.at(0);
	}


	//Sort the trees by the sum of the weight
	sort(trees_.begin(), trees_.end(), [](const BinaryTree& b1, const BinaryTree& b2){
				//b1Sum is used for calculate the weight sum of b1
				int b1Sum = 0;
				//b2Sum is used for calculate the weight of the b2
				int b2Sum = 0;
				//Traverse b1 to get the total weight of b1
				b1.traverse([&b1Sum](const string& text, double weight){
							b1Sum += weight;
						});
				//Traverse b2 to get the total weight of b2
				b2.traverse([&b2Sum](const string& text, double weight){
							b2Sum += weight;
						});

				//Compare the sum of two trees
				return b1Sum > b2Sum;
				});

	//Right element is use less, therefore declare the last tree as right
	BinaryTree right = trees_.at(trees_.size() - 1);
	//Left element is use more than right, declare left after right
	BinaryTree left = trees_.at(trees_.size() - 2);
	trees_.pop_back();
	trees_.pop_back();

	//Generate a new tree
	BinaryTree newTree = BinaryTree(left, right);
	//Push the new tree to the array
	trees_.push_back(newTree);

	//Recursively doing the same process until there is only one tree left in the vector.
	return applyHuffman();
}

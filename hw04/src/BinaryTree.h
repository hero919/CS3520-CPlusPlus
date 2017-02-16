/*
 * BinaryTree.h
 *
 *  Created on: Feb 7, 2017
 *      Author: zeqingzhang
 */


#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <string>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>

namespace hw04{
/*
 * Define a class BinaryTree which include a string text, a int weight,
 * and a vector, if it is the leaf, the vector will be empty, else the leaf includes
 * two BinaryTree
 */
class BinaryTree{

public:
	BinaryTree(/*Constructor includes a string text or integer weight*/
				const std::string s, const int weight);

	BinaryTree(/*Constructor includes BinaryTree left or BinaryTree right */
				const BinaryTree& left,const BinaryTree& right);


	/*
	 * Traverses in depth-first search order to print the tree input the output stream
	 * used for output the result
	 */
	void printTree(std::ostream& output) const;

	/*Input two iterators, one starts as begin and one represents the end of the iterator
	 *  traverses the tree to obtain the text string of one leaf node. Output the result
	 *  using string type
	 *  */
	std::string get(std::string::iterator&  iter, const std::string::iterator end) const;

private:
	/*string field using text_ to represent */
	std::string text_;

	/*using field weight to represent the weight value */
	const int weight_ = 0;

	/*The binary tree vector which used for store the left and right Binary tree */
	std::vector<BinaryTree> vector_;
};
}


#endif /* BINARYTREE_H_ */

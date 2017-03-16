/*
 * BinaryTree.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: zeqingzhang
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;
using namespace hw06;

//Initialize the constructor
BinaryTree::BinaryTree(const string& s, const int weight) : text_(s), weight_(weight){

}



//Initialize the constructor
BinaryTree::BinaryTree(const BinaryTree& left,const BinaryTree& right){
	//First push the left element to the vector then push the second one as right element
	children_.push_back(left);
	children_.push_back(right);

	//Initialize the sum to be 0
	int sum = 0;
	//Add all the weight of its children
	for(BinaryTree tree : children_){
		sum += tree.weight_;
	}
	weight_ = sum;
}



std::string BinaryTree::get(std::string::iterator&  iter, const std::string::iterator& end) const{
	//Create the root point to the current tree
	const BinaryTree* root = this;

	//Using iterator to loop
	while(iter != end){
		//If the input is A or L, go left first and then check whether it is the leaf
		if(((*iter) == 'A' || (*iter) == 'L')){
			root = &(root->children_.at(0));
			if(root -> children_.size() == 0){
				iter++;
				return root->text_;
			}
			iter++;
			continue;
		}

		////If the input is D or R, go right first and then check whether it is the leaf
		 if(((*iter) == 'D' || (*iter) == 'R')){
			root = &(root->children_.at(1));
			if(root -> children_.size() == 0){
				iter++;
				return root->text_;
			}
			iter++;
			continue;
		}

		 throw domain_error("Input the invalid Parameter!");
	}
	//Other case return empty
	return "";
}



/**
 * Decode a path.  The path parameter is copied
 * because it could be modified by the method.
 * @return The decoded path.
 */
std::string BinaryTree::decode(/** The path to be decoded. */
		     std::string path) const{
	string result = "";
	//Iterate over the string, if it reaches the leaf then adding the leaf value
	//to result
	for (auto iter = path.begin(); iter < path.end(); ) {
		result += get(iter, path.end());
	 }
	return result;
}



double BinaryTree::getWeight() const noexcept{
	//Return weight_ directly since we have already set the weight_ value to be total
	return weight_;
}












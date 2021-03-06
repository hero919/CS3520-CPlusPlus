/*
 * BinaryTree.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: zeqingzhang
 */

#include "BinaryTree.h"
using namespace std;
using namespace hw05;

//Initialize the constructor
BinaryTree::BinaryTree(const string& s, const int weight) : text_(s), weight_(weight){

}



//Initialize the constructor
BinaryTree::BinaryTree(const BinaryTree& left,const BinaryTree& right){
	//First push the left element to the vector then push the second one as right element
	children_.push_back(left);
	children_.push_back(right);
}


void BinaryTree::printTree(std::ostream& output) const noexcept{
	//Check whether it is the leaf
	if(children_.size() == 0){
		output << text_;
	}else{
		//For each level of the tree, print left first then using space to separate
		//Then close the bracket
		output << "(";
		children_.at(0).printTree(output);
		output<< " ";
		children_.at(1).printTree(output);
		output << ")";
	}
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


void BinaryTree::traverse(/** The function to apply to every leaf node. */
              const std::function<void(const std::string& text, double weight)>& function)
		const noexcept{
	//Base case, if the given tree is a leaf
	if(children_.size() == 0){
		function(text_, weight_);
	}else{
		//If it has children then traverse each subtree
		children_.at(0).traverse(function);
		children_.at(1).traverse(function);
	}
}

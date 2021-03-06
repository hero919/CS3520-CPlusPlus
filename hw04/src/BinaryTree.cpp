/*
 * BinaryTree.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: zeqingzhang
 */

#include "BinaryTree.h"
using namespace std;
using namespace hw04;

//Initialize the constructor
BinaryTree::BinaryTree(const string s, const int weight) : text_(s), weight_(weight){

}



//Initialize the constructor
BinaryTree::BinaryTree(const BinaryTree& left,const BinaryTree& right){
	//First push the left element to the vector then push the second one as right element
	vector_.push_back(left);
	vector_.push_back(right);
}


void BinaryTree::printTree(std::ostream& output) const{
	//Check whether it is the leaf
	if(vector_.size() == 0){
		output << text_;
	}else{
		//For each level of the tree, print left first then using space to separate
		//Then close the bracket
		output << "(";
		vector_.at(0).printTree(output);
		output<< " ";
		vector_.at(1).printTree(output);
		output << ")";
	}
}

std::string BinaryTree::get(std::string::iterator&  iter, const std::string::iterator end) const{
	//Create the root point to the current tree
	const BinaryTree* root = this;

	//Using iterator to loop
	while(iter != end){
		//If the input is A or L, go left first and then check whether it is the leaf
		if(((*iter) == 'A' || (*iter) == 'L')){
			root = &(root->vector_.at(0));
			if(root -> vector_.size() == 0){
				iter++;
				return root->text_;
			}
			iter++;
			continue;
		}

		////If the input is D or R, go right first and then check whether it is the leaf
		 if(((*iter) == 'D' || (*iter) == 'R')){
			root = &(root->vector_.at(1));
			if(root -> vector_.size() == 0){
				iter++;
				return root->text_;
			}
			iter++;
			continue;
		}
	}
	//Other case return empty
	return "";
}

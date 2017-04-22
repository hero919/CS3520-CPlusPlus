/*
 * BTerm.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: zeqingzhang
 */



#include "BTerm.h"
#include <set>
#include <memory>
#include <iostream>
#include <string>

using namespace hw10;
using namespace std;

BTerm::BTerm(const string& name, shared_ptr<Term> left, shared_ptr<Term> right) :
		left_(left), right_(right),name_(name){

};


BTerm::~BTerm(){

}

shared_ptr<Term> BTerm::getLeft() const noexcept{
	//Get left
	return left_;
}


shared_ptr<Term> BTerm::getRight() const noexcept{
	//Get right
	return right_;
}

string BTerm::getName() const noexcept{
	return name_;
}

void BTerm::traverse(std::function<void(std::shared_ptr<Term> term)> preAction){
	//Applied function to this then applied function to left first then right
	//DFS all the way down to left then go riht
	preAction(shared_from_this());
	shared_from_this()->getLeft()->traverse(preAction);
	shared_from_this()->getRight()->traverse(preAction);
}

void BTerm::print(ostream& out) const noexcept{
	//The strategy to print the tree
	//Using getLeft and getRight to get left and right child
	out << "[";
	out << getName() << ":";
	getRight()->print(out);
	out << "]";
	out << "(";
	getLeft()->print(out);
	out << ")";
}








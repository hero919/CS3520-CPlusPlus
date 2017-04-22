/*
 * ATerm.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: zeqingzhang
 */


#include "ATerm.h"
#include <set>
#include <memory>
#include <iostream>
#include <string>

using namespace std;
using namespace hw10;


ATerm::ATerm(shared_ptr<Term> left, shared_ptr<Term> right): left_(left),right_(right){

}

ATerm::~ATerm(){

}

shared_ptr<Term> ATerm::getLeft() const noexcept {
	return left_;
}

shared_ptr<Term> ATerm::getRight() const noexcept {
	return right_;
}


void ATerm::traverse(function<void(shared_ptr<Term> term)> preAction) {
	//Applied traverse to this first then applied it to left and right
	preAction(shared_from_this());
	shared_from_this()->getLeft()->traverse(preAction);
	shared_from_this()->getRight()->traverse(preAction);
}

void ATerm::print(ostream& out) const noexcept {
	//Print left then print right, divide and concor
	getLeft()->print(out);
	cout<< " ";
	getRight()->print(out);
}




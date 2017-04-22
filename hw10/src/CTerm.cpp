/*
 * CTerm.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: zeqingzhang
 */

#include "CTerm.h"
#include <memory>
using namespace std;
using namespace hw10;

CTerm::CTerm(){

}

CTerm::~CTerm(){

}

shared_ptr<BTerm> CTerm::getUpper() const noexcept {
	//Because upper_ is weak pointer, convert to shared pointer
	return upper_.lock();
}

void CTerm::setUpper(shared_ptr<BTerm> upper) {

	// If the parameter is empty, then throw an exception
	if(!upper) {
		throw domain_error("the parameter cannot be empty!");
	}

	//If we didn't set the upper yet.
	if(upper_.expired()){
		//Initialize the boolean
		bool finalResult = 0;
		//make shared pointer point to this
		shared_ptr<Term> t(shared_from_this());
		//Create lambda function that applied in traverse
		auto func = [&finalResult, &t](shared_ptr<Term> s){
			//check whether children contains this
			if(t == s){
				finalResult = 1;
			}
		};

		//Applied upper to check
		upper->traverse(func);
		//If this is the child of its upper link then it is valid
		//else throw domain error.
		if(finalResult){
			upper_ = upper;
			return;
		}
		throw domain_error("Attempt to set the upper link of a term to a term named "+
								upper->getName() + " that is not an ancestor");
	}
}


void CTerm::traverse(function<void(shared_ptr<Term> term)> preAction) {
	//Only traverse it self
	preAction(shared_from_this());
}

void CTerm::print(ostream& out) const noexcept {
	//check whether it has upper, if yes, print it.
	if(getUpper()){
		out << getUpper()->getName();
	}

}



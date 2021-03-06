/*
 * Band.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: zeqingzhang
 */

#include "Band.h"
#include "Musician.h"
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>


using namespace std;
using namespace hw07;


Band::Band(const string& name):name_(name){

}



Band::~Band(){
	cout <<"Deleting "<< name_<< endl;
}


std::string Band::getName() const noexcept{
	return name_;
}



void Band::add(std::shared_ptr<Musician> musician) noexcept{
	//If the musician is null pointer, return
	if(!musician || hasMember(musician)){
		return;
	}
	members_.insert(musician);
}


void Band::remove(std::shared_ptr<Musician> musician) noexcept{
	//check if the input is null or the band didn't has the musician
	//return nothing, else reomve the element from set
	if(!musician || !hasMember(musician)){
		return;
	}
	members_.erase(musician);
}


bool Band::hasMember(/** The musician that is being queried. */
		 std::shared_ptr<Musician> musician) noexcept{
	//Check the null pointer, if the pointer is null then return false
	if(!musician){
		return false;
	}

	//else check whether the band has that musician
	return members_.find(musician) != members_.end();
}




void Band::print(/** The output stream to which the information is to be printed. */
	     std::ostream& out) const noexcept{
	//Print the band name
	out << "Band" << " " << name_ << endl;

	//Print all the musicians in the band
	for(auto member : members_){
		//If the pointer is null then we don't need to print anything
		if( member!= nullptr){
			//else print the name of each musician
			out <<" "<< member->getName() << endl;
		}
	}
}



/*
 * Person.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: zeqingzhang
 */

#include "Person.h"
#include <set>
#include <string>
#include <memory>
#include <iostream>


using namespace std;
using namespace hw08;


Person::Person(/** The name of the person. */
           const std::string& name):name_(name){

}

Person::~Person(){
	cout << "Deleting " << name_<< endl;
}


string Person::getName() const noexcept{
	return name_;
}


 void Person::knows(std::shared_ptr<Person> knownPerson) noexcept{
	 //check if the we have already known the person, then we don't need to add him
	 if(!knownPerson){
		 return;
	 }
	 knownPersons_.insert(knownPerson);
 }


 void Person::trusts(std::shared_ptr<Person> trustedPerson) noexcept{
	 //If we have already trusted the person, then we don't need to add it to the trusted set
	 if(!trustedPerson){
		 return;
	 }
	 trustedPersons_.insert(trustedPerson);
 }

 /**
  * Find all persons who are known or trusted to
  * specified numbers of levels.
  * @return The set of persons that are
  * sufficiently well-known and trusted.
  */
 std::set<std::shared_ptr<Person>>
 Person::getWebOfTrust(/** The maximum (inclusive) level of knowing. */
		int maxKnown,
		/** The maximum (inclusive) level of trusting. */
		int maxTrusted) const noexcept{
	 //Create the result set
	 set<shared_ptr<Person>> result;

	 //If the maxKnown and maxTrusted is used, then we need to return the result
	 if(maxKnown <= 0 && maxTrusted <= 0){
		 return result;
	 }


	 //If the maxKnown is greater than 0
	 if(maxKnown > 0){
		 //Add this person's known person to the result
		 for(shared_ptr<Person> p : knownPersons_){
			 //If it is already in the list, we don't need to add it to avoid the infinite recursion.
			 if(result.find(p) != result.end()){
				 continue;
			 }
			 result.insert(p);
			 //Recursion the process and minus one to the maxKnown
			 set<std::shared_ptr<Person>> s(p->getWebOfTrust(maxKnown - 1, maxTrusted));
			 result.insert(s.begin(), s.end());
		 }
	 }


	 //If the maxTrusted is greater than 0
	 if(maxTrusted > 0){
		 //Add this person's trust person to the set
		 for(shared_ptr<Person> p : trustedPersons_){
			 //If this person is already in the set then we don't need to add it.
			 if(result.find(p) != result.end()){
				 continue;
			 }
			 result.insert(p);
			 //Recursion the process
			 set<std::shared_ptr<Person>> s(p->getWebOfTrust(maxKnown, maxTrusted - 1));
			 result.insert(s.begin(), s.end());
		 }
	 }
	 return result;
 }






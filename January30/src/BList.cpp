#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "BList.h"
using namespace std;
using namespace blist;
BList::BList(// Missing Code Part 3
		const std::string& lowerBound,
		        /** The upper bound. */ const std::string& upperBound):
		        		lowerBound_(lowerBound), upperBound_(upperBound)
{

}

void BList::addString(const string& text) {

  // If the string is not within the bounds,
  // then throw an exception explaining what happened.

	if (text < lowerBound_ || text > upperBound_) {
    string msg = "Attempt to add " + text +
      " to a list of strings bounded by " + lowerBound_ +
      " and " + upperBound_;
    throw domain_error(msg);
  }

  // Add the string to the list.

  list_.push_back(text);
}

void BList::sortList(bool sortInAscendingOrder) noexcept {

  // Missing Code Part 4
	if(!sortInAscendingOrder){
		sort(list_.begin(), list_.end(), [](const string& a, const string& b){
			return a > b;
		});
	}else{
		sort(list_.begin(), list_.end());
	}

}

void BList::printList(ostream& out) const noexcept {

  // A comma is supposed to separate the strings
  // so add a comma (and space) at the beginning
  // of each string except for the first one.

  string separator = "";

  // Missing Code Part 5
  for(string s : list_){
	  out << separator << s;
	  separator = ", ";
  }

  out << endl;
}

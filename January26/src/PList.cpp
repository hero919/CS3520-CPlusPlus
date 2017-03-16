
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "PList.h"
using namespace std;
using namespace plist;
PList::PList(int lowerBound){ // Missing Code Part 1
	//Why it is private but still can be accessed
	PList::lowerBound_ = lowerBound;
}
double PList::addNumber(double number) {
	if(number < PList::lowerBound_){
		throw std::domain_error("The input number is smaller than the lower bound.");
	}
	list_.push_back(number);
	return number;
}


double PList::computeAverage() noexcept {
	double count = 0;
	double total = 0;
	for(double num : PList::list_){
		count++;
		total += num;
	}
	return total/count;
}

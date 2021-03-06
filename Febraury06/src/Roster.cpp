/*
 * Roster.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: zeqingzhang
 */


#include "Roster.h"
using namespace std;
using namespace roster;

void Roster::addStudent(const Student& student) noexcept {
  studentList_.push_back(student);
}

double Roster::computeAverage(std::function<bool(const Student&)> func)// Missing Code Part 2
    const noexcept {
  double gpaSum = 0.0;
  int count = 0;
  for (auto iter = studentList_.begin(); iter != studentList_.end(); ++iter) {
      // Missing Code Part 3
	  if(func(*iter)){
		continue;
	  }
	  gpaSum += iter->getGPA();
	  count++;
  }

  return gpaSum / count;
}

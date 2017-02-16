/*
 * Student.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: zeqingzhang
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "Student.h"
using namespace std;
using namespace roster;

Student::Student(const string& firstName,
                 const string& lastName,
                 const string& emailAddress,
                 double gpa)
  : firstName_(firstName), lastName_(lastName),
    emailAddress_(emailAddress), gpa_(gpa) {}

Student::Student(istream& in) {
  string line;
  getline(in, line);
  stringstream studentLine(line);
  try {
    getline(studentLine, firstName_, '|');
    getline(studentLine, lastName_, '|');
    getline(studentLine, emailAddress_, '|');
    string gpaString;
    getline(studentLine, gpaString);
    gpa_ = stod(gpaString);
  } catch (const exception& e) {
    throw domain_error("Wrong format for a student record");
  }
}

string Student::getFirstName() const noexcept {
  return firstName_;
}

string Student::getLastName() const noexcept {
  return lastName_;
}

string Student::getEmailAddress() const noexcept {
  return emailAddress_;
}

double Student::getGPA() const noexcept {
  return gpa_;
}

void Student::print(ostream& out) const noexcept {
  out << firstName_ << " " << lastName_ << " <" << emailAddress_ << "> has GPA " << gpa_ << "\n";
}



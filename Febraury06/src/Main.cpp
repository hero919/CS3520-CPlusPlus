#include <stdexcept>
#include <iostream>
#include "Roster.h"
using namespace std;
using namespace roster;

/**
 * @namespace roster Maintain a roster of students
 * and compute the average GPA of a selection of
 * them, the number of students in a selection,
 * and print a selection.
 *
 * @author Ken Baclawski
 */

/**
 * Main program that reads the standard input to
 * construct a list of students and then computes
 * some averages.
 * @return The exit status.  Normal status is 0.
 */

bool studentsStartingWithA(const Student& s){
	  if(s.getFirstName().at(0) == 'A'){
		  return true;
	  }
	  return false;
  }
int main() {
  Roster roster;

  // Read the standard input, construct student
  // records and add them to the roster.

  while (true) {
    try {
      Student student(cin);
      roster.addStudent(student);
    } catch (const domain_error& error) {

      // Stop reading when any error occurs.

      break;
    }
  }

  // Compute the average of all students whose
  // first name begins with "A".

  // Missing Code Part 4
  auto studentsStartingWithA = [](const Student& student) {
	  if(student.getFirstName().at(0) == 'A'){
		  return 0;
	  }
	  return 1;
  };

  cout << "A student average is " << roster.computeAverage(studentsStartingWithA) << endl;

  // Print all students whose GPA is at least 3.5

  // Missing Code Part 5
  auto printStudents = [](const Student& student) {
     if (student.getGPA() >= 3.5) {
       student.print(cout);
     }
     return true;
   };
  roster.computeAverage(printStudents);

  // Print the number of students whose GPA is at least 3.4


  // Missing Code Part 6
  int studentCount = 0;
    auto countStudents = [&studentCount](const Student& student) {
      if (student.getGPA() >= 3.4) {
        ++studentCount;
      }
      return true;
    };
    try{
  roster.computeAverage(countStudents);
    } catch (const exception& e){

    }
  cout << "There are " << studentCount << " students with GPA at least 3.4" << endl;

  // Normal return

  return 0;
}

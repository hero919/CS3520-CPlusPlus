#include <vector>
#include <iostream>
#include "Musician.h"

using namespace std;
using namespace musician;

/**
 * @namespace musician Musicians package using
 * raw pointers.
 *
 * @author Ken Baclawski
 */

/**
 * Main program to test the Musician class using
 * raw pointers.
 * @return The status code.
 */
int main() {

  // Construct some musicians: Alice, Madonna,
  // John and Ringo.

	Musician* alice = new Musician("Alice");
	Musician* madonna = new Musician("Madonna");
	Musician* john = new Musician("John");
	Musician* ringo = new Musician("Ringo");
  // Fill in the missing code here...

  // Construct two vectors for holding pointers to
  // musicians: who and what
	vector<Musician*> who;
	vector<Musician*> what;

  // Fill in the missing code here...

  // Put alice, john and ringo in who.

  who.push_back(alice);
  who.push_back(john);
  who.push_back(ringo);

  // Put alice and madonna in what.

  what.push_back(alice);
  what.push_back(madonna);

  // In a loop, print the names of the musicians
  // in who and their instruments.
  for(Musician* musician : who){
	  if(musician){
		cout<<musician->getName()<<endl;
	  }
  }

  // Fill in the missing code here...

  // In a loop, delete the musicians in who

//  for(Musician* musician : who){
//	  if(musician){
//		  delete musician;
//	  }
//  }
//
//  // Fill in the missing code here...
//
//  // In a loop, delete the musicians in what
//  for (Musician* musician : what) {
//      if (musician) {
//        delete musician;
//      }
//    }

  // Fill in the missing code here...

  return 0;
}

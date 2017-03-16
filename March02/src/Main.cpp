#include <vector>
#include <iostream>
#include <memory>
#include "Musician.h"

using namespace std;
using namespace musician;

/**
 * @namespace musician1 Musicians package using
 * managed pointers.
 *
 * @author Ken Baclawski
 */

/**
 * Main program to test the Musician class using
 * managed pointers.
 * @return The status code.
 */
int main() {

	// Construct some musicians.

	  shared_ptr<Musician> alice(make_shared<Musician>("Alice"));
	  shared_ptr<Musician> madonna(make_shared<Musician>("Madonna"));
	  shared_ptr<Musician> john(make_shared<Musician>("John"));
	  shared_ptr<Musician> ringo(make_shared<Musician>("Ringo"));

	  // Put the musicians into some vectors.

	  vector<shared_ptr<Musician>> who;
	  vector<shared_ptr<Musician>> what;

	  // Put alice, john and ringo in who.

	  who.push_back(alice);
	  who.push_back(john);
	  who.push_back(ringo);

	  // Put alice and madonna in what.

	  what.push_back(alice);
	  what.push_back(madonna);

	  // In a loop, print the names of the musicians
	  // in who and their instruments.

	  for (shared_ptr<Musician> musician : who) {
	    if (musician) {
	      cout << musician->getName() << endl;
	    }
	  }

	  return 0;
}

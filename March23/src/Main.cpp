#include <iostream>
#include <memory>
#include "Musician.h"

using namespace std;
using namespace musician;

/**
 * @namespace musician Musicians package using
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

  // Construct some persons and musicians.

  shared_ptr<Person> bob(make_shared<Person>("Bob"));
  shared_ptr<Musician> alice(make_shared<Musician>("Alice", "Piano"));
  shared_ptr<Musician> madonna(make_shared<Musician>("Madonna", "Voice"));
  shared_ptr<Musician> john(make_shared<Musician>("John", "Guitar"));
  shared_ptr<Musician> ringo(make_shared<Musician>("Ringo", "Drums"));

  // Print names and instruments.

  cout << bob->getName() << " " << bob->getInstrument() << endl;
  cout << ringo->getName() << " " << ringo->getInstrument() << endl;

  /* The output of the above statements should be:

Bob does not play an instrument
Ringo Drums

   */

  // Return with normal status.

  return 0;
}

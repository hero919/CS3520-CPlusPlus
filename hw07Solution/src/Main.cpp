#include <iostream>
#include <vector>
#include <stdexcept>

#include "Band.h"
#include "Musician.h"

using namespace std;
using namespace hw07;

/**
 * @namespace hw07 Solution to Homework #7.
 * Pointers and Memory Management.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for the pointer and memory
 * management program.
 * @return The status code.  Normal is 0.  If an
 * exception is thrown, then return 1.
 */
int main() {
  try {

    // Construct the two bands.

    Band who("who");
    Band what("what");

    // Construct the musicians.

    auto alice(make_shared<Musician>("Alice"));
    auto madonna(make_shared<Musician>("Madonna"));
    auto john(make_shared<Musician>("John"));
    auto ringo(make_shared<Musician>("Ringo"));

    // Add the musicians to the bands.

    who.add(alice);
    who.add(john);
    who.add(ringo);

    what.add(alice);
    what.add(madonna);

    // Print the bands.

    who.print(cout);
    what.print(cout);
  } catch (const exception& e) {

    // Show any exception that is thrown

    cerr << "Failure due to: " << e.what() << endl;
    return 1;
  }
  return 0;
}

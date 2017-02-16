#include <stdexcept>
#include <iostream>
#include "PList.h"
using namespace std;
using namespace plist;

/**
 * @namespace plist List of lower bounded numbers.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for testing the lower bounded list.
 * @return The exit status.  Normal status is 0.
 */
int main() {
  try {

    // Create a lower bounded list object.
    // The lower bound is 0, so only positive
    // numbers can be in the list.

    PList pList(0.0);

    // Add some numbers to the list.

    pList.addNumber(1.0);
    pList.addNumber(5.0);

    // This should throw an exception:

   // pList.addNumber(-1.0);
    cout<< pList.computeAverage() <<endl;
  } catch (const domain_error& error) {

    // The error message should be:
    // "Attempt to add the number -1.000000 to a list of numbers bounded below by 0"

    cout << error.what() << endl;
    return 1;
  }


  // Normal return

  return 0;
}


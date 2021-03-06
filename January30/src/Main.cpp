#include <stdexcept>
#include <iostream>
#include "BList.h"
using namespace std;
using namespace blist;

/**
 * @namespace blist List of bounded strings.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for testing the bounded list.
 * @return The exit status.  Normal status is 0.
 */
int main() {
  try {

    // Create a bounded list object.  The lower
    // bound is J and upper bound is M, so only
    // strings between J and M (inclusive) can be
    // in the list.

    BList bList("J", "M");

    // Add some strings to the list.

    bList.addString("JSON");
    bList.addString("Lisa");

    // Sort the list in ascending order.

    bList.sortList(true);

    // The output should be "JSON, Lisa"

    bList.printList(cout);

    // Sort the list in descending order

    bList.sortList(false);

    // The output should be "Lisa, JSON"

    bList.printList(cout);

    // This should throw an exception:

    bList.addString("Q");


    string path("ADDDAADD");
//     for (auto iter = path.begin(); iter < path.end(); ) {
//     cout << top.get(iter, path.end());
//     }

  } catch (const domain_error& error) {

    // The error message should be:
    // "Attempt to add Q to a list of strings bounded by J and M"

    cout << error.what() << endl;
    return 1;
  }

  // Normal return

  return 0;
}

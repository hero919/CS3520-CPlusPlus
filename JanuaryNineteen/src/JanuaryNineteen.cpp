#include "Truth.h"
#include <string>
#include <iostream>
using namespace truth;
using namespace std;

/**
 * @namespace truth Print the locations of all occurrences of "truth" in
 * the standard input.  A location is a line number and a character position.
 * For example "5:3" means line 5 and character position 3.  Lines and
 * positions start with 0, so this is actually the fourth character in the
 * sixth line.  The program always exits with status code 0.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for finding the truth.
 * @return The exit status.  Normal status is 0.
 */
int main() {

  // Construct a truth finder object.

  Truth truth;

  // Read the standard input and use the truth finder on each line.

  while (true) {

    // Read one line from the standard input.

    string line;
    getline(cin, line);
    if (!cin) {
      break;
    }

    // Find the truth.

    truth.findTruth(line);
  }

  // Return the status.

  return 0;
}

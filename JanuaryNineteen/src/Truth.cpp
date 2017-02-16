/*
 * Truth.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: zeqingzhang
 */

#include "Truth.h"
using namespace std;
using namespace truth;

void Truth::findTruth(string input){
	// Keep track of the line number.

	  int lineNumber = 0;

	  // Read all of the standard input

	  for (;;) {
	    string line;
	    getline(cin, line);
	    if (!cin) {
	      break;
	    }

	    // Loop over all characters in the line that can be the beginning of truth.

	    for (unsigned int i = 0; i < line.length(); ++i) {

	      // Extract the five-character substring starting at i.

	      const string word = line.substr(i, 5);
	      if (word == "truth") {
	        cout << lineNumber << ":" << i << endl;
	      }
	    }

	    // Increment the line number

	    lineNumber++;
	  }

	  // Return normal status.
}


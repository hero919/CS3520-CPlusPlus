//============================================================================
// Name        : SampleCpp.cpp
// Author      : Zeqing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
using namespace std;

/**
 * @namespace occurrences Print the locations of all occurrences of "truth" in
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

  // Fill in the missing code: Part 1

  // Read all of the standard input

	int lineNumber = 0;
	string result = "Can't find the truth";
	for (;;) {
		string line;
		getline(cin, line);

		if (!cin) {
		  break;
		}
		if(line.length() < 5){
			continue;
		}

	bool flag = false;
    for(int i = 0; i <= line.length() - 5; i++){
    	string substring = line.substr(i, i + 5);
    	if(substring.compare("truth") == 0){
    		result =  to_string(lineNumber) + ":" + to_string(i);
    		flag = true;
    		break;
    	}
    }
    if(flag){
    	break;
    }

    // Loop over all characters in the line that can be the beginning of truth.

    // Fill in the missing code: Part 2

    // Increment the line number
    lineNumber++;
  }

  // Return normal status.

  cout << result << endl;

  return 0;
}

//============================================================================
// Name        : hw01.cpp
// Author      : Zeqing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

/**
 * @namespace hw01 Reads the standard input, breaking it up
 * into sentences which are printed.
 *
 * @author Zeqing Zhang
 */


#include <iostream>
#include <string>
using namespace std;

/**
 * Main program for breaking the sentences
 * @return The exit status. If there is no valid
 * sentence return 1, if there exists valid sentence return 0
 */
int main() {
		//Declare the input and output
	    string input;
	    string output;

	    //Make a flag to determine whether there exists any sentence
	    //or not.
	    bool returnNum = 1;

	    //Read the input line by line
	    for(;;){
	    	getline(cin, input);
	    	//If fail to read return the flag
	    	if(!cin){
	    		return returnNum;
	    	}

	    	//Loop the character for each line
	    	for (int i = 0; i < input.length(); i++) {
	    		char character = input[i];
	    		//Adding the character to the existing sentence
	    		output += character;

	    		//Determine whether it is the sentence.
	    		if (character == '?' || character == '.' || character == '!') {
	    			//Find the sentence change the exist code
	    			returnNum = 0;
	    			cout << output << endl;
	    			//If it is the sentence clear the output
	    			output = "";
	    		}
	    	}
	    }

	    return returnNum;
}


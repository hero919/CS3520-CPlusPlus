#include "HashTagger.h"
#include <string>
#include <iostream>
using namespace hw02;
using namespace std;
/**
 * @namespace hw02 Solution to Homework #2. Read
 * the standard input and maintain a list of all
 * "hashtags". There are two methods: one for
 * extracting the hashtags from a string and
<Untitled>
 * storing them in a list, and another to print
 * all of the hashtags.
 *
 * @author Ken Baclawski
 */
/**
 * Main program for the solution to Homework #2.
 * @return The status code. Normal status is 0.
 */
int main() {
	 // Construct an object for extracting the
	 // hashtags.
	 HashTagger hashTagger;
	 // Read the standard input and extract the
	 // hashtags.
	 while (true) {
	 // Read one line from the standard input.
	 string line;
	 getline(cin, line);
	 if (!cin) {
	 break;
	 }
	 // Get all of the hashtags on the line.
	 hashTagger.getTags(line);
	 }
	 // Print the hashtags.
	 hashTagger.printTags();
	 // Return the status.
	 return 0;
}

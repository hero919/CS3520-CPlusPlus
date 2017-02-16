#include "MedianWord.h"
#include <iostream>
using namespace std;
using namespace medianw;

/**
 * @namespace medianw Median word task.  This
 * program reads words from the standard input and
 * computes the median word or pair of words.  The
 * median word is the middle word (or pair of
 * words) in sorted order.  If the number of words
 * is odd, then there is exactly one median word.
 * If the number of words is even (and at least
 * 2), then there are two median words.  If no
 * words are entered, then print that no words
 * were entered and return status code 1.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for the median word task.
 * @return The exit status: 0 if there is at least
 * one word in the input and 1 otherwise.
 */
int main() {

  // The utility for computing the median word.

  MedianWord medianFinder;

  // Read all input words.

  string word;
  while (cin >> word) {
    medianFinder.addWord(word);
  }

  // Check for the possibility of no words.

  if (medianFinder.isEmpty()) {
    cout << "No words were entered." << endl;
    return 1;
  }

  // Find and print the median word or words.

  cout << medianFinder.findMedian() << endl;

  // Status code is 0.

  return 0;
}

/*
 * MedianWord.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: zeqingzhang
 */

#include "MedianWord.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace medianw;
using namespace std;

/** Add a word to the collection of words. */
 void MedianWord::addWord(/** The word to be added to the collection. */
                std::string word){
	 wordList_.push_back(word);
 }

 /**
  * Determine whether the collection of words is empty.
  * @return True if the collection of words is empty.
  */
 bool MedianWord::isEmpty() const{
	 return wordList_.empty();
 }

 /**
  * Compute the median word.
  * @return The median word or pair of words.  If
  * the word list is empty return an empty
  * string.
  */
 std::string MedianWord::findMedian(){
	 unsigned int mid = wordList_.size()/2;
	 sort(wordList_.begin(), wordList_.end());
	 return (wordList_.size() % 2 == 0) ? wordList_.at(mid) + " " + wordList_.at(mid + 1):
			 wordList_.at(mid);
 }

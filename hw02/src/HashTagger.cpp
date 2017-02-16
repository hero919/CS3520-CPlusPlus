/*
 * HashTagger.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: zeqingzhang
 */

#include "HashTagger.h"
#include <iostream>
#include <string>
using namespace hw02;
using namespace std;

void HashTagger::getTags(std::string line){
	//Start the track for reading the input
	bool track = false;
	//Track whether there are other # after one # in the same line
	bool testEmbedded = false;
	//Create a vector to store the start points of the #
	vector<int> startPoints;
	//Track the end point
	int end = 0;

	//Loop the sentence character by character
	for(unsigned int i = 0; i < line.length(); i++){
		char character = line[i];

		//If the word is not finished and start with a new sharp
		if(character == '#' && track == true){
				testEmbedded = true;
				startPoints.push_back(i);
		}

		//Just Start with a new words
		if(character == '#' && track == false){
				track = true;
				if(!testEmbedded){
					startPoints.clear();
				}
				startPoints.push_back(i);
		}

		if(track && (character == ' '
								|| character == '.'
										|| character =='?'
												|| character =='!')){
				//If we meet the ending point
				end = i;
				track = false;
				for(unsigned int startPoint : startPoints){
					hashWords_.push_back(line.substr(startPoint, end - startPoint));
				}
				//Ending the embedded track because this is the end of the sentence
				testEmbedded = false;

				//test whether it is the end of the line
				if(i == line.length() - 1){
					continue;
				}
		}

		//If we get the end of the line
		if(track && (i == (line.length() - 1))){
				//because it is the end of the line therefore the length should be i - start + 1
				//Using i + 1 directly here
				end = i + 1;
				track = false;
				for(unsigned int startPoint : startPoints){
					//we get the end point of the sentence
					hashWords_.push_back(line.substr(startPoint, end - startPoint));
				}
				testEmbedded = false;
		}
	}
}


void HashTagger::printTags(){
	//Loop over the whole list and print the word one by one
	for(std::string s: hashWords_){
		std::cout<< s <<std::endl;
	}
}

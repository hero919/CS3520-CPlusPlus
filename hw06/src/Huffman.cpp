/*
 * Huffman.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: zeqingzhang
 */

#include "Huffman.h"
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>

using namespace std;
using namespace hw06;

Huffman::Huffman(const std::string& trainingData){

		//Initialize a map
		map<char, int> map;

		//Loop over the characters in training data
		for(unsigned int i = 0; i < trainingData.size(); i++){
			//If the key exists in the map, increment its value by 1 each time
			if(map.count(trainingData.at(i)) == 1){
				map[trainingData.at(i)] =  map[trainingData.at(i)] + 1;
			}else{
				//If the key doesn't exists insert the key and make the value to be 1
				map.insert({trainingData.at(i), 1});
			}
		}

		//Check invalid training data
		if(map.size() < 2){
			throw domain_error("The training data is not sufficient for a Huffman decoder");
		}

		auto compareByTreeWeight = [](const BinaryTree& b1, const BinaryTree& b2){
			//Compare the value by decending order
			return b1.getWeight() < b2.getWeight();
		};

		//Initialize a multiset and elements in ascending order
		std::multiset<BinaryTree, decltype(compareByTreeWeight)> set(compareByTreeWeight);

		//Loop over the map
		for (auto it = map.begin(); it != map.end(); ++it){
				string text(1, it->first);
				BinaryTree b(text, it->second);
				set.insert(b);
		}

		//Loop over the set until it combined to one tree
		while(set.size() > 1){
			std::multiset<BinaryTree>::const_iterator it(set.begin());
			//The right tree is always the smaller one
			BinaryTree right = *(it);
			//the left tree is little bigger
			BinaryTree left = *(++it);
			BinaryTree newTree(left, right);
			//Erase the last two smallest elements
			set.erase(set.begin());
			set.erase(set.begin());
			set.insert(newTree);
		}
		//Set the final tree to coder_
		coder_ = *(set.begin());

}


std::string Huffman::decode(/** The encoded data. */
	     const std::string& encodedData) const{

	//Call the decode method
	return coder_.decode(encodedData);
}




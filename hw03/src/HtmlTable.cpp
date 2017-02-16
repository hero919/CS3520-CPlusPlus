/*
 * HtmlTable.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: zeqingzhang
 */

#include "HtmlTable.h"
#include <iostream>
#include <string>
#include <vector>
using namespace hw03;
using namespace std;


//Initialize the HtmlTable structure
HtmlTable :: HtmlTable(const unsigned int cols) : columns_(cols){
}


void HtmlTable::addEntry(const string& input) noexcept{

	//If the vector is empty or the number of the input reach the maximum column number
	//Create a new vector to store.
	if(input_.empty() || input_.at(input_.size() - 1).size() == columns_){
		vector<string> list;
		list.push_back(input);
		input_.push_back(list);
		return;
	}

	//Other cases, just add the new input to the last existing vector
	input_.at(input_.size() - 1).push_back(input);

}

const string HtmlTable::toString() noexcept{
	//Initialize the result
	string result = "";
	//Start with the given table title
	result.append("<table border='1'>");
	result.append("\n");
	//Loop the vector in the vector
	for(vector<string> v : input_){
		//For the last line, if the size of the last line is not fully fill the vector
		//ignore that line
		if(v.size() != columns_){
			continue;
		}
		//At each new line, append <tr> at the front of the line
		result.append("<tr>");

		//Corner case, only one element
		if(v.size() == 1){
			result.append("<td>" + v.at(0));
			result.append("\n");
			continue;
		}

		//Set a pre string to check whether the next one is the same as
		//the previous one
		string pre = v.at(0);
		int count = 1;
		for(unsigned int i = 1; i < v.size(); i++){
			//If this is the last line of code
			if(i == v.size() - 1){
				if(v.at(i) == pre){
					count++;
					result.append("<td colspan='" + to_string(count) + "'>" + pre);
				}

				//If the last element is different and previous has multiple same elements
				//print both
				if(v.at(i) != pre && count > 1){
					result.append("<td colspan='" + to_string(count) + "'>" + pre);
					result.append("<td>" + v.at(i));
				}

				if(v.at(i) != pre && count == 1){
					result.append("<td>" + pre);
					result.append("<td>" + v.at(i));
				}
				continue;
			}

			//If it is not the last element and it needs to continue count the number of
			//duplicates to be printed
			if(v.at(i) == pre){
				count++;
				continue;
			}
			//common case with different letters
			if(v.at(i) != pre && count == 1){
				result.append("<td>" + pre);
				pre = v.at(i);
				continue;
			}

			//common case with the same letter
			if(v.at(i) != pre && count != 1){
				result.append("<td colspan='" + to_string(count) + "'>" + pre);
				pre = v.at(i);
				count = 1;
			}
		}
		result.append("\n");
	}

	//Append the ending string
	result.append("</table>");
	return result;
}

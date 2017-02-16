/*
 * HashTagger.h
 *
 *  Created on: Jan 19, 2017
 *      Author: zeqingzhang
 */

#ifndef HASHTAGGER_H_
#define HASHTAGGER_H_
#include <string>
#include <vector>

namespace hw02{
	class HashTagger {
	public:
		/*
		 * Get the all the tags beginning with #
		 */
		void getTags(/*input a line of string */
				std::string line);

		/*
		 *Print all the tags
		 */
		void printTags();

	private:
		//Create a new vector used for saving the strings
		std::vector<std::string> hashWords_;
	};
}
#endif /* HASHTAGGER_H_ */

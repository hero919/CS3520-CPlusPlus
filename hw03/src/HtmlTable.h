/*
 * HtmlTable.h
 *
 *  Created on: Jan 26, 2017
 *      Author: zeqingzhang
 */

#ifndef HTMLTABLE_H_
#define HTMLTABLE_H_
#include <vector>
#include <string>
using namespace std;

namespace hw03{
	class HtmlTable{
		public:
			void addEntry(/*Add the string to the defined structure */
						const string& input) noexcept;

			/*Convert the structure to the string */
			const string toString() noexcept;

			/*Define HtmlTable*/
			HtmlTable(const unsigned int cols);


		private:
			/*Define the number of columns shows in the final string */
			const unsigned int columns_;

			/*Define 2-D vector to store the string */
			std::vector<std::vector<std::string> > input_;
	};
}

#endif /* HTMLTABLE_H_ */

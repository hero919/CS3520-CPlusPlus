#include <vector>
#include <iostream>
#include "HtmlTable.h"
using namespace std;
using namespace hw03;

/**
 * @namespace hw03 HTML table task. Read an
 * integer from the standard input and use it as
 * the number of columns in the table. Then read
CS3520 Programming in C++ Spring 2017
 * words from the standard input and use them as
 * entries in an HTML table. Only complete rows
 * are shown in the table. For example, if the
 * number of columns is 5 and the last row has
 * only 4 words, then that row is not shown in the
 * table. If there are multiple adjacent words in
 * the same row, then they shown be shown only
 * once in the table, with colspan set equal to
 * the number of repeated words. Multiple,
 * adjacent words in the same column are not given
 * any special treatment.
 *
 * @author Ken Baclawski
 */
/**
 * Main program for the HTML table task.
 * @return The status code. Normal status is 0.
 * If there is no input or the number of columns
 * is not positive, then return 1.
 */
int main() {
	// Read the number of columns
	int columnCount = 0;
	if (!(cin >> columnCount)) {
		return 1;
	}
	// The number of columns must be positive
	if (columnCount <= 0) {
		return 1;
	}
	// Construct the HtmlTable object
	HtmlTable::HtmlTable htmlTable(columnCount);
	// Read the table entries
	string path("hello");
	path.end();
	string entry;
 	 while (cin >> entry) {
 		 htmlTable.addEntry(entry);
 	 }
 	 // Print the HTML table
 	 cout << htmlTable.toString() << endl;
 	 // Normal status
 	 return 0;
}

#include "HtmlTable.h"
#include <iostream>
using namespace std;
using namespace hw03;

HtmlTable::HtmlTable(unsigned int columnCount) : columnCount_(columnCount) {}

void HtmlTable::addEntry(const std::string& entry) noexcept {

  // Compute the index of the last row of the table.

  int lastRow = 0;

  // Check for an empty table.

  if (table_.empty()) {

    // If the table is empty, then add a new row.
    // The index of the last row is 0.

    vector<string> newRow;
    table_.push_back(newRow);
    lastRow = 0;
  } else {

    // If the table is not empty, check whether
    // the last row is full.

    lastRow = table_.size() - 1;
    if (table_.at(lastRow).size() == columnCount_) {

      // The last row is full, so a new row must
      // be added.

      vector<string> newRow;
      table_.push_back(newRow);
      ++lastRow;
    }
  }

  // Add the entry to the last row.

  table_.at(lastRow).push_back(entry);
}

std::string HtmlTable::toString() const noexcept {

  // The string with the HTML format of the table

  string htmlFormat("<table border='1'>\n");

  // Loop over the rows of the table.

  for (const vector<string>& row : table_) {

    // Only full columns are included.

    if (row.size() == columnCount_) {

      // Mark the start of a row in the HTML format.

      htmlFormat += "<tr>";

      // Loop over the entries in the row.

      for (unsigned int i = 0; i < columnCount_; ++i) {
	const string& entry(row.at(i));

	// Count the number of repeats for this entry.

	int repeatCount = 0;
	for (unsigned int j = i + 1; j < columnCount_; ++j) {
	  if (entry == row.at(j)) {
	    ++repeatCount;
	  } else {
	    break;
	  }
	}

	// Add the entry to the HTML format.

	if (repeatCount == 0) {
	  htmlFormat += "<td>" + entry;
	} else {
	  htmlFormat += "<td colspan='" + to_string(repeatCount + 1) + "'>" + entry;

	  // If there are repeats, then skip them.

	  i += repeatCount;
	}
      }

      // Close the HTML row.

      htmlFormat += "\n";
    }
  }

  // Close the table and return it.

  htmlFormat += "</table>";
  return htmlFormat;
}

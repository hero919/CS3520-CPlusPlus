#ifndef HW03_HTMLTABLE_H
#define HW03_HTMLTABLE_H

#include <vector>
#include <string>

namespace hw03 {

/**
 * Construct an HTML table.
 *
 * @author Ken Baclawski
 */
class HtmlTable {
public:
  /**
   * Nested class.
   */
  class Entry {
  public:
    /** The entry. */
    const std::string text;
  };

  /**
   * Construct an empty table with specified
   * number of columns.
   */
  HtmlTable(/** The number of columns. */
	    unsigned int columnCount);

  /**
   * Add an entry to the table.
   */
  void addEntry(/** The entry to be added. */
		const std::string& entry) noexcept;

  /**
   * Print the table in HTML format.  If the last
   * row does not have enough entries, then it is
   * not included.  If entries are repeated then
   * they are shown only once with a colspan set
   * to the number of occurrences.
   * @return A string with the formatted table.
   */
  std::string toString() const noexcept;

private:
  /**
   * The number of columns in the table.  This
   * could also be an unsigned int.
   */
  const unsigned int columnCount_ = 0;

  /**
   * The table of entries.
   */
  std::vector<std::vector<std::string>> table_;
};

}

#endif

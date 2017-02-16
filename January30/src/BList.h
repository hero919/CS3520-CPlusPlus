#ifndef BLIST_BLIST_H
#define BLIST_BLIST_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

namespace blist {

/**
 * A list of strings constrained to be inclusively
 * between two bounds.  For example, if the lower
 * bound is "J", then the strings must start with
 * a character that is J or later.  One can add to
 * the list, sort the list and print the list.
 *
 * @author Ken Baclawski
 */
class BList {
public:
  /**
   * Construct a bounded list.
   */
  BList(/** The lower bound. */ const std::string& lowerBound,
        /** The upper bound. */ const std::string& upperBound);

  /**
   * Add a string to the list.
   * @throws domain_error if the string is outside the bounds.
   */
  // Missing Code Part 1
  void addString(const std::string& tex);

  /**
   * Sort the list of strings.
   */
  void sortList(/** Whether to sort in ascending order. */
                bool sortInAscendingOrder) noexcept;

  /**
   * Print the list of strings to an output stream.
   */
  // Missing Code Part 2
  void printList(std::ostream& out) const noexcept;

private:
  /** The inclusive lower bound. */
  const std::string lowerBound_;
  /** The inclusive upper bound. */
  const std::string upperBound_;
  /** The list of bounded strings. */
  std::vector<std::string> list_;
};

}

#endif

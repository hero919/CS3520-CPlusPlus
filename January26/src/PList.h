#ifndef PLIST_PLIST_H
#define PLIST_PLIST_H

#include <vector>
#include <stdexcept>

namespace plist {

/**
 * A list of numbers constrained to be strictly
 * above a lower bound.  For example, if the lower
 * bound is 0, then the numbers must all be
 * positive.  One can add to the list and compute
 * the average of the list.
 *
 * @author Ken Baclawski
 */
class PList {
public:
  /**
   * Construct an lower bounded list.
   */
  PList(/** The lower bound. */ int lowerBound);

  /**
   * Add a number to the list.
   * @return the number that was added.
   * @throws domain_error if the number is not allowed.
   */
  double addNumber(/** The new number to add to the list. */
                   double number);

  /**
   * Compute the average value of the numbers.
   * @return the average value or the lower bound
   * if the list is empty.
   */
  double computeAverage() noexcept;


private:
  /** The strict lower bound. */
  int lowerBound_ = 0.0;
  /** The list of lower bounded numbers. */
  std::vector<double> list_;
};

}

#endif

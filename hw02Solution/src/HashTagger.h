#ifndef HW02_HASHTAGGER_H
#define HW02_HASHTAGGER_H

#include <vector>
#include <string>

namespace hw02 {

/**
 * Extract and save hashtags in text.  The
 * hashtags are kept in a list.  The methods
 * extract the hashtags from strings and print the
 * hashtags.
 *
 * @author Ken Baclawski
 */
class HashTagger {
public:
  /**
   * Extract the hashtag from a string.
   * Note that it is okay in this assignment for
   * the parameter to be a string rather than a
   * constant reference to a string.
   */
  void getTags(/** The string from which the
                   hashtags are to be extracted. */
               const std::string& line) noexcept;

  /**
   * Print all the hashtags.
   */
  void printTags() const noexcept;

private:
  /**
   * The list of hashtags.
   */
  std::vector<std::string> list_;
};

}

#endif

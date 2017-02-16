#ifndef MEDIANW_MEDIANWORD_H
#define MEDIANW_MEDIANWORD_H

#include <string>
#include <vector>

namespace medianw {

/**
 * Utility for computing the median word.
 *
 * @author Ken Baclawski
 */
class MedianWord {
public:
  /** Add a word to the collection of words. */
  void addWord(/** The word to be added to the collection. */
                 std::string word);

  /**
   * Determine whether the collection of words is empty.
   * @return True if the collection of words is empty.
   */
  bool isEmpty() const;

  /**
   * Compute the median word.
   * @return The median word or pair of words.  If
   * the word list is empty return an empty
   * string.
   */
  std::string findMedian();

private:
  /** The collection of words. */
  std::vector<std::string> wordList_;
};

}

#endif

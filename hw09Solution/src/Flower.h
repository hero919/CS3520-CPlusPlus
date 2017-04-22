#ifndef HW09_FLOWER_H
#define HW09_FLOWER_H

#include <string>

namespace hw09 {

/**
 * A flower object.  It has a species.
 * @author Ken Baclawski
 */
class Flower {
public:
  /**
   * Construct a flower from a string.
   */
  Flower(/** The species of the flower. */
        const std::string& species);

  /**
   * The flower species.
   * @return The species of the flower.
   */
  std::string getSpecies() const noexcept;

private:
  /** The flower species. */
  const std::string species_;
};

}

#endif

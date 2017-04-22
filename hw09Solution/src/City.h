#ifndef HW09_CITY_H
#define HW09_CITY_H

#include <string>

namespace hw09 {

/**
 * A city object.  It has a name.
 * @author Ken Baclawski
 */
class City {
public:
  /**
   * Construct a city from a string.
   */
  City(/** The name of the city. */
        const std::string& name);

  /**
   * The city name.
   * @return The name of the city.
   */
  std::string getName() const noexcept;

private:
  /** The city name. */
  const std::string name_;
};

}

#endif

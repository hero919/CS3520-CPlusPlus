#ifndef HW07_BAND_H
#define HW07_BAND_H

#include <set>
#include <string>
#include <memory>
#include <iostream>

namespace hw07 {

class Musician;

/**
 * An band has a name and a set of musicians.
 *
 * @author Ken Baclawski
 */
class Band {
public:
  /**
   * Construct a band.
   */
  Band(/** The band name. */ const std::string& name);

  /**
   * Destruct a band.
   */
  ~Band();

  /**
   * Get the name of the band.
   * @return The band name.
   */
  std::string getName() const noexcept;

  /**
   * Add a musician to a band.
   */
  void add(/** The musician that is joining the band. */
           std::shared_ptr<Musician> musician) noexcept;

  /**
   * Remove a musician from a band.
   */
  void remove(/** The musician that is leaving the band. */
              std::shared_ptr<Musician> musician) noexcept;

  /**
   * Determine whether a musician is in a band.
   * @return True if the musician is in this band.
   */
  bool hasMember(/** The musician that is being queried. */
		 std::shared_ptr<Musician> musician) noexcept;

  /**
   * Print the band information on an output stream.
   */
  void print(/** The output stream to which the information is to be printed. */
	     std::ostream& out) const noexcept;

private:
  /** The band name. */
  const std::string name_;

  /** The set of musicians who are members of the band. */
  std::set<std::shared_ptr<Musician>> members_;
};

}

#endif

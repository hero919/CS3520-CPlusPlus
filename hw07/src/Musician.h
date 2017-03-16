#ifndef HW07_MUSICIAN_H
#define HW07_MUSICIAN_H

#include <string>
#include <memory>

namespace hw07 {

class Band;

/**
 * A musician has a name.
 *
 * @author Ken Baclawski
 */
class Musician : public std::enable_shared_from_this<Musician> {
public:
  /**
   * Construct a musician with a name.
   */
  Musician(/** The name of the musician. */
           const std::string& name);

  /**
   * Destructor.
   */
  ~Musician();

  /**
   * The name of the musician.
   * @return The musician name.
   */
  std::string getName() const noexcept;

  /**
   * Add a musician to a band.
   */
  void add(/** The band that the musician is joining. */
           std::shared_ptr<Band> band) noexcept;

  /**
   * Remove a musician from a band.
   */
  void remove(/** The band that the musician is leaving. */
              std::shared_ptr<Band> band) noexcept;

  /**
   * Determine whether a musician is in a band.
   * @return True if the musician is in the specified band.
   */
  bool isMember(/** The band that is being queried. */
		std::shared_ptr<Band> band) noexcept;

private:
  /** The musician name. */
  const std::string name_;
};

}

#endif

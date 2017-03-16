#ifndef MUSICIAN_MUSICIAN_H
#define MUSICIAN_MUSICIAN_H

#include <set>
#include <string>

using namespace std;
namespace musician {

class Musician;

/**
 * A musician.  Each musician has a name.
 * @author Ken Baclawski
 */
class Musician {
public:
  /**
   * Construct a musician.
   */
  Musician(/** The name of the musician. */
           const std::string& name);

  /**
   * Destruct a musician.
   */
  ~Musician();

  /**
   * Get the name of the musician.
   * @return The musician name.
   */
  std::string getName() const noexcept;

private:
  /** The name of the musician. */
  const std::string name_;
};

}

#endif

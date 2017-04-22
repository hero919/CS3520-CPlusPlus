#ifndef HW09_BIJECTION_H
#define HW09_BIJECTION_H

#include <map>
#include <stdexcept>

namespace hw09 {

/**
 * A template for a one-to-one correspondence.
 * Each object of one type (the domain) is mapped
 * to an object of another type (the range) in
 * both directions.  It is implemented using two
 * maps, one in each direction.
 *
 * @author Ken Baclawski
 */
template</** The domain type. It must have a conversion to boolean. */ typename D,
         /** The range type. It must have a conversion to boolean. */ typename R>
class Bijection {
public:
  /**
   * Construct a bijection with no mappings.
   */
  Bijection() {}

  /**
   * Destruct a bijection.
   */
  ~Bijection() {
    forward_.clear();
    backward_.clear();
  }

  /**
   * Add a new mapping in both directions.  Both
   * objects are tested to be sure that the
   * conversions to boolean both result in true.
   * @throw domain_error if one of the objects
   * converts to false.
   */
  void map(/** The domain object. */ D a,
	   /** The range object. */ R b) {
    if (a) {
      if (b) {
	forwardUnmap(a);
	backwardUnmap(b);
	forward_.insert({a, b});
	backward_.insert({b, a});
      } else {
	throw std::domain_error("Attempt to map to an invalid object");
      }
    } else {
      throw std::domain_error("Attempt to map an invalid object");
    }
  }

  /**
   * Unmap an object in the forward direction.  If
   * the object is not mapped, then the method
   * does nothing.
   */
  void forwardUnmap(/** The object to be unmapped. */ D a) noexcept {
    if (forward_.count(a) > 0) {
      backward_.erase(forward_.at(a));
      forward_.erase(a);
    }
  }

  /**
   * Unmap an object in the backward direction.
   * If the object is not mapped, then the method
   * does nothing.
   */
  void backwardUnmap(/** The object to be unmapped. */ R b) noexcept {
    if (backward_.count(b) > 0) {
      forward_.erase(backward_.at(b));
      backward_.erase(b);
    }
  }

  /**
   * Get the value of an object in the forward direction.
   * @return The value of the specified object or
   * the empty object if it is not mapped.
   */
  R forward(/** The object whose value is desired. */ D a) {
    if (forward_.count(a) > 0) {
      return forward_.at(a);
    } else {
      return R();
    }
  }

  /**
   * Get the value of an object in the backward direction.
   * @return The value of the specified object or
   * the empty object if it is not mapped.
   */
  D backward(/** The object whose value is desired. */ R b) {
    if (backward_.count(b) > 0) {
      return backward_.at(b);
    } else {
      return D();
    }
  }

private:
  /** The forward mapping. */
  std::map<D, R> forward_;
  /** The backward mapping. */
  std::map<R, D> backward_;
};

}

#endif

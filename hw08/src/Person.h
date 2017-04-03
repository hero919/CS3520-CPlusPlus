#ifndef HW08_PERSON_H
#define HW08_PERSON_H

#include <set>
#include <string>
#include <memory>

namespace hw08 {

/**
 * A person.  Each person has a name and sets of
 * persons that are known and trusted.
 */
class Person {
public:
  /**
   * Construct a person.
   */
  Person(/** The name of the person. */
           const std::string& name);

  /**
   * Destruct a person.
   */
  ~Person();

  /**
   * Get the name of the person.
   * @return The person name.
   */
  std::string getName() const noexcept;

  /**
   * Add a person that is known.
   */
  void knows(/** The person that is known. */
	     std::shared_ptr<Person> knownPerson) noexcept;

  /**
   * Add a person that is trusted.
   */
  void trusts(/** The person that is trusted. */
	     std::shared_ptr<Person> trustedPerson) noexcept;

  /**
   * Find all persons who are known or trusted to
   * specified numbers of levels.
   * @return The set of persons that are
   * sufficiently well-known and trusted.
   */
  std::set<std::shared_ptr<Person>>
  getWebOfTrust(/** The maximum (inclusive) level of knowing. */
		int maxKnown,
		/** The maximum (inclusive) level of trusting. */
		int maxTrusted) const noexcept;

private:
  /** The name of the person. */
  const std::string name_;

  /** The known persons. */
  std::set<std::shared_ptr<Person>> knownPersons_;

  /** The trusted persons. */
  std::set<std::shared_ptr<Person>> trustedPersons_;
};

}

#endif

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test of the trust package
#include <boost/test/unit_test.hpp>

#include <vector>
#include <iostream>
#include <memory>
#include "Person.h"

using namespace std;
using namespace hw08;

/**
 * @namespace trust Simple web of trust among people.  A person has a set of
 * people that they know and also people that they trust.  From one person one
 * can find everyone that are on a chain that has links that are trust to any
 * number of levels, and acquaintances to a limited number of levels.
 *
 * @author Ken Baclawski
 */

BOOST_AUTO_TEST_CASE(trust_test1) {

  // Construct three people

  shared_ptr<Person> alice(make_shared<Person>("Alice"));
  shared_ptr<Person> madonna(make_shared<Person>("Madonna"));
  shared_ptr<Person> john(make_shared<Person>("John"));
  shared_ptr<Person> ringo(make_shared<Person>("Ringo"));

  // Set acquaintances and trusts

  alice->trusts(madonna);
  john->trusts(ringo);
  madonna->trusts(ringo);
  ringo->knows(alice);
  alice->knows(john);

  // Test the people who are in the web of trust of ringo.

  set<shared_ptr<Person>> set1 = { alice, madonna };
  BOOST_CHECK(ringo->getWebOfTrust(1, 1) == set1);
  set<shared_ptr<Person>> set2 = { alice, madonna, john, ringo };
  BOOST_CHECK(ringo->getWebOfTrust(2, 1) == set2);

  // Clear the persons to eliminate cycles.

  alice->clear();
}

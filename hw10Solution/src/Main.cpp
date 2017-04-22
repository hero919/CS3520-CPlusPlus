#include <iostream>
#include "ATerm.h"
#include "BTerm.h"
#include "CTerm.h"

using namespace std;
using namespace hw10;

/**
 * @namespace hw10 Solution to Homework #10.
 * Polymorphism and Smart Pointers.
 *
 * @author Ken Baclawski
 */

/**
 * Test the term hierarchy.
 * @return The status code.  Normal status is 0.
 */
int main() {
  try {

    // Make some terms.

    auto c1 = make_shared<CTerm>();
    auto c2 = make_shared<CTerm>();
    auto c3 = make_shared<CTerm>();
    auto c4 = make_shared<CTerm>();
    auto a = make_shared<ATerm>(c1, c2);
    auto b1 = make_shared<BTerm>(a, c3, "B1");
    auto b2 = make_shared<BTerm>(b1, c4, "B2");

    // Set some upper links

    c1->setUpper(b1);
    c2->setUpper(b1);
    c3->setUpper(b2);
    c4->setUpper(b2);

    // Print the term structure

    cout << *b2 << endl;
  } catch (const domain_error& error) {
    cout << "Error: " << error.what() << endl;
  }

  try {

    // Make some terms.

    auto c1 = make_shared<CTerm>();
    auto c2 = make_shared<CTerm>();
    auto c3 = make_shared<CTerm>();
    auto c4 = make_shared<CTerm>();
    auto a = make_shared<ATerm>(c1, c2);
    auto b1 = make_shared<BTerm>(a, c3, "B1");
    auto b2 = make_shared<BTerm>(b1, c4, "B2");

    // Set some upper links

    c1->setUpper(b1);
    c2->setUpper(b1);
    c3->setUpper(b2);
    c4->setUpper(b1);

    // Print the term structure

    cout << *b2 << endl;
  } catch (const domain_error& error) {
    cout << "Error: " << error.what() << endl;
  }

  // End the program

  return 0;
}

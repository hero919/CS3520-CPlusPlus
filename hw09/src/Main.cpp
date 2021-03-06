#include <iostream>
#include <memory>

#include "Bijection.h"
#include "City.h"
#include "Flower.h"

using namespace std;
using namespace hw09;


/**
 * @namespace hw09  Generic bijection template.
 *
 * @author Ken Baclawski
 */

/**
 * Test program for the Bijection template.
 */

int main() {
  try {

    // Construct the empty bijection from pointers
    // to cities to pointers to flowers.

    // Missing Code Part 1
	 Bijection<shared_ptr<City>, shared_ptr<Flower>> bijection;

    // Construct some cities and flowers.

    auto plymouth(make_shared<City>("Plymouth"));
    auto newYork(make_shared<City>("New York"));
    auto mayflower(make_shared<Flower>("Mayflower"));
    auto rose(make_shared<Flower>("Rose"));

    // Make the mayflower the flower of both cities.

    // Missing Code Part 2
    bijection.map(plymouth,mayflower);
    bijection.map(newYork,mayflower);

    // Now correctly make mayflower the flower of
    // Plymouth and rose the flower of New York.
    // Missing Code Part 3
    bijection.forwardUnmap(newYork);
    bijection.map(newYork, rose);




    // Print the plymouth official flower

    auto plymouthFlower = bijection.forward(plymouth);
      // Missing Code Part 4

    if (plymouthFlower) {
      cout << plymouthFlower->getSpecies() << endl;
    } else {
      cout << "Plymouth has no official flower" << endl;
    }

    // Show the newYork official flower

    auto newYorkFlower = bijection.forward(newYork);
      // Missing Code Part 5

    if (newYorkFlower) {
      cout << newYorkFlower->getSpecies() << endl;
    } else {
      cout << "New York has no official flower" << endl;
    }
  } catch (const exception& e) {
    cout << "An exception was thrown: " << e.what() << endl;
  }
  return 0;
}

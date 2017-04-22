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

    // Construct the empty bijection.

    Bijection<shared_ptr<City>, shared_ptr<Flower>> officialFlowers;

    // Construct some cities and flowers.

    auto plymouth(make_shared<City>("Plymouth"));
    auto newYork(make_shared<City>("New York"));
    auto mayflower(make_shared<Flower>("Mayflower"));
    auto rose(make_shared<Flower>("Rose"));

    // Map the cities to the flowers.

    officialFlowers.map(plymouth, mayflower);
    officialFlowers.map(newYork, mayflower);
    officialFlowers.map(newYork, rose);

    // Show the plymouth official flower

    auto plymouthFlower = officialFlowers.forward(plymouth);
    if (plymouthFlower) {
      cout << plymouthFlower->getSpecies() << endl;
    } else {
      cout << "Plymouth has no official flower" << endl;
    }

    // Show the newYork official flower

    auto newYorkFlower = officialFlowers.forward(newYork);
    if (newYorkFlower) {
      cout << newYorkFlower->getSpecies() << endl;
    } else {
      cout << "New York has no official flower" << endl;
    }

    // Try a bad mapping.

    officialFlowers.map(shared_ptr<City>(), mayflower);
  } catch (const exception& e) {
    cout << "An exception was thrown: " << e.what() << endl;
  }
  return 0;
}

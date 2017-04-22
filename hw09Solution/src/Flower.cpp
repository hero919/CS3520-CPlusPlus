#include <string>

#include "Flower.h"

using namespace std;
using namespace hw09;

Flower::Flower(const string& species)
  : species_(species) {}

string Flower::getSpecies() const noexcept {
  return species_;
}

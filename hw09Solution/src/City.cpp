#include <string>

#include "City.h"

using namespace std;
using namespace hw09;

City::City(const string& name)
  : name_(name) {}

string City::getName() const noexcept {
  return name_;
}

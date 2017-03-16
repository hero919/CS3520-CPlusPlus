#include <string>
#include <iostream>
#include "Musician.h"

using namespace std;
using namespace musician;

Musician::Musician(const string& name) : name_(name) {}

Musician::~Musician() {
  cout << "Deleting " << name_ << endl;
}

string Musician::getName() const noexcept {
  return name_;
}

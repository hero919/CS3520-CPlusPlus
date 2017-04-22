#include "Band.h"
#include "Musician.h"

using namespace std;
using namespace hw07;

Musician::Musician(const string& name) : name_(name) {}

Musician::~Musician() {
  cout << "Deleting " << name_ << endl;
}

string Musician::getName() const noexcept {
  return name_;
}

void Musician::add(shared_ptr<Band> band) noexcept {
  if (band) {
    band->add(shared_from_this());
  }
}

void Musician::remove(shared_ptr<Band> band) noexcept {
  if (band) {
    band->remove(shared_from_this());
  }
}

bool Musician::isMember(shared_ptr<Band> band) noexcept {
  if (band) {
    return band->hasMember(shared_from_this());
  }
  return false;
}

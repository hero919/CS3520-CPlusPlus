#include "Band.h"
#include "Musician.h"

using namespace std;
using namespace hw07;

Band::Band(const string& name) : name_(name) {}

Band::~Band() {
  cout << "Deleting " << name_ << endl;
}

string Band::getName() const noexcept {
  return name_;
}

void Band::add(shared_ptr<Musician> musician) noexcept {
  if (musician) {
    members_.insert(musician);
  }
}

void Band::remove(shared_ptr<Musician> musician) noexcept {
  if (musician) {
    members_.erase(musician);
  }
}

bool Band::hasMember(shared_ptr<Musician> musician) noexcept {
  return members_.count(musician) > 0;
}

void Band::print(ostream& out) const noexcept {
  out << "Band " << name_ << endl;
  for (auto m : members_) {
    out << "  " << m->getName() << endl;
  }
}


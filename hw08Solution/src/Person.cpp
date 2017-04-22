#include <string>
#include <iostream>
#include "Person.h"

using namespace std;
using namespace hw08;

Person::Person(const string& name) : name_(name) {}

Person::~Person() {
  cout << "Deleting " << name_ << endl;
  clear();
}

void Person::clear() noexcept {
  knownPersons_.clear();
  trustedPersons_.clear();
}

string Person::getName() const noexcept {
  return name_;
}

void Person::knows(shared_ptr<Person> knownPerson) noexcept {
  if (knownPerson) {
    knownPersons_.insert(knownPerson);
  }
}

void Person::trusts(shared_ptr<Person> trustedPerson) noexcept {
  if (trustedPerson) {
    trustedPersons_.insert(trustedPerson);
  }
}

set<shared_ptr<Person>> Person::getWebOfTrust(int maxKnown, int maxTrusted) const noexcept {
  set<shared_ptr<Person>> web;
  if (maxKnown > 0) {
    for (auto knownPerson : knownPersons_) {
      if (knownPerson) {
	web.insert(knownPerson);
	auto knownPersons = knownPerson->getWebOfTrust(maxKnown - 1, maxTrusted);
	web.insert(knownPersons.begin(), knownPersons.end());
      }
    }
  }
  if (maxTrusted > 0) {
    for (auto trustedPerson : trustedPersons_) {
      if (trustedPerson) {
	web.insert(trustedPerson);
	auto trustedPersons = trustedPerson->getWebOfTrust(maxKnown, maxTrusted - 1);
	web.insert(trustedPersons.begin(), trustedPersons.end());
      }
    }
  }
  return web;
}

#include <memory>
#include "Term.h"
#include "BTerm.h"
using namespace std;
using namespace hw10;

Term::Term() {}

Term::~Term() {}

string Term::getName() const noexcept {
  return string();
}

shared_ptr<Term> Term::getLeft() const noexcept {
  return shared_ptr<Term>();
}

shared_ptr<Term> Term::getRight() const noexcept {
  return shared_ptr<Term>();
}

shared_ptr<BTerm> Term::getUpper() const noexcept {
  return shared_ptr<BTerm>();
}

void Term::setUpper(shared_ptr<BTerm> term) {}

#include "ATerm.h"

using namespace std;
using namespace hw10;

ATerm::ATerm(shared_ptr<Term> left, shared_ptr<Term> right)
  : left_(left), right_(right) {

  // The components cannot be empty.

  if (!left) {
    throw domain_error("Attempt to construct a B term with an empty left component");
  }
  if (!right) {
    throw domain_error("Attempt to construct a B term with an empty right component");
  }
}

ATerm::~ATerm() {}

shared_ptr<Term> ATerm::getLeft() const noexcept {
  return left_;
}

shared_ptr<Term> ATerm::getRight() const noexcept {
  return right_;
}

void ATerm::traverse(function<void(shared_ptr<Term> term)> preAction) {
  preAction(shared_from_this());
  left_->traverse(preAction);
  right_->traverse(preAction);
}

void ATerm::print(ostream& out) const noexcept {
  out << *left_ << " " << *right_;
}

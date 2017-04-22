#include "BTerm.h"

using namespace std;
using namespace hw10;

BTerm::BTerm(shared_ptr<Term> left, shared_ptr<Term> right, const string& name)
  : left_(left), right_(right), name_(name) {

  // The components and name cannot be empty.

  if (!left) {
    throw domain_error("Attempt to construct a B term with an empty left component");
  }
  if (!right) {
    throw domain_error("Attempt to construct a B term with an empty right component");
  }
  if (name.empty()) {
    throw domain_error("Attempt to construct a B term with an empty name");
  }
}

BTerm::~BTerm() {}

string BTerm::getName() const noexcept {
  return name_;
}

shared_ptr<Term> BTerm::getLeft() const noexcept {
  return left_;
}

shared_ptr<Term> BTerm::getRight() const noexcept {
  return right_;
}

void BTerm::traverse(function<void(shared_ptr<Term> term)> preAction) {
  preAction(shared_from_this());
  left_->traverse(preAction);
  right_->traverse(preAction);
}

void BTerm::print(ostream& out) const noexcept {
  out << "[" << name_ << ": " << *right_ << "](" << *left_ << ")";
}

#include "BTerm.h"
#include "CTerm.h"

using namespace std;
using namespace hw10;

CTerm::CTerm() {}

CTerm::~CTerm() {}

shared_ptr<BTerm> CTerm::getUpper() const noexcept {
  return upper_.lock();
}

void CTerm::setUpper(shared_ptr<BTerm> upper) {

  // Check that the new upper term is not empty

  if (!upper) {
    throw domain_error("Attempt to set an upper link to an empty term");
  }

  // The operation is idempotent, so ignore it if
  // the upper link is already set.

  if (!upper_.expired()) {
    return;
  }

  // Check that the upper term is an ancestor by
  // traversing the subtree at this term.

  bool foundThis = false;
  function<void(shared_ptr<Term>)> checkForThis =
    [&](shared_ptr<Term> term)
    {
      if (term == shared_from_this()) {
	foundThis = true;
      }
      return;
    };
  upper->traverse(checkForThis);

  // If this term is not in the subtree at the
  // upper term, then throw an exception.

  if (!foundThis) {
    throw domain_error("Attempt to set the upper link of a term to a term named " +
                       upper->getName() + " that is not an ancestor");
  }

  // Finally, the upper link can be set.

  upper_ = upper;
}

void CTerm::traverse(function<void(shared_ptr<Term> term)> preAction) {
  preAction(shared_from_this());
}

void CTerm::print(ostream& out) const noexcept {
  shared_ptr<BTerm> sharedUpper = upper_.lock();
  if (sharedUpper) {
    out << sharedUpper->getName();
  } else {
    out << "unknown";
  }
}

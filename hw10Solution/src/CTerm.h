#ifndef HW10_CTERM_H
#define HW10_CTERM_H

#include "Term.h"

namespace hw10 {

class BTerm;

/**
 * A C term.  This kind of term has an optional upper link.
 *
 * @author Ken Baclawski
 */
class CTerm : virtual public Term {
public:
  /**
   * Construct a C term.
   */
  CTerm();

  /**
   * Destructor.
   */
  virtual ~CTerm();

  /**
   * Get the upper link.
   * @return The upper link. It can be empty.
   */
  virtual std::shared_ptr<BTerm> getUpper() const noexcept override;

  /**
   * Set the upper link.
   * @throw domain_error if the parameter is empty.
   */
  virtual void setUpper
  (/** The term that is to be the upper link. */
   std::shared_ptr<BTerm> term) override;

  /**
   * Traverse the subtree at this term in
   * depth-first search manner.  A function is
   * invoked when each term is first encountered,
   * i.e., the preAction.
   */
  virtual void traverse
  (/** The function to be invoked when a term is encountered. */
   std::function<void(std::shared_ptr<Term> term)> preAction) override;

  /**
   * Print the term recursively on an output
   * stream.  This is the virtual function that
   * implements the output stream insertion
   * operator.
   * @return The output stream
   */
  virtual void print
  (/** The output stream on which to print the term. */
   std::ostream& out) const noexcept;

private:
  /** The upper link. It can be empty. */
  std::weak_ptr<BTerm> upper_;
};

}

#endif

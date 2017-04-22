#ifndef HW10_BTERM_H
#define HW10_BTERM_H

#include "Term.h"

namespace hw10 {

/**
 * A B term.  This kind of term has a name and
 * both left and right components.  The name and
 * the components can never be empty.
 *
 * @author Ken Baclawski
 */
class BTerm : virtual public Term {
public:
  /**
   * Construct a B term.
   * @throws domain_error if any parameter is empty.
   */
  BTerm(/** The left component. It cannot be empty. */
	std::shared_ptr<Term> left,
	/** The right component. It cannot be empty. */
	std::shared_ptr<Term> right,
	/** The name of the term. It cannot be empty. */
	const std::string& name);

  /**
   * Destructor.
   */
  virtual ~BTerm();

  /**
   * Get the name of the term or blank if the term
   * has no name.
   * @return The term name.
   */
  virtual std::string getName() const noexcept override;

  /**
   * Get the left component.
   * @return The left component. It cannot be empty.
   */
  virtual std::shared_ptr<Term> getLeft() const noexcept override;

  /**
   * Get the right component.
   * @return The right component. It cannot be empty.
   */
  virtual std::shared_ptr<Term> getRight() const noexcept override;

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
  /** The left component. It cannot be empty. */
  std::shared_ptr<Term> left_;

  /** The right component. It cannot be empty. */
  std::shared_ptr<Term> right_;

  /** The name. It cannot be empty. */
  const std::string name_;
};

}

#endif

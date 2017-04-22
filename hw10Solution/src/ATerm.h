#ifndef HW10_ATERM_H
#define HW10_ATERM_H

#include "Term.h"

namespace hw10 {

/**
 * An A term.  This kind of term has both left and
 * right components but no name.  The components
 * can never be empty.
 *
 * @author Ken Baclawski
 */
class ATerm : virtual public Term {
public:
  /**
   * Construct an A term.
   * @throws domain_error if either the left or
   * the right parameter is empty.
   */
  ATerm(/** The left component. It cannot be empty. */
	std::shared_ptr<Term> left,
	/** The right component. It cannot be empty. */
	std::shared_ptr<Term> right);

  /**
   * Destructor.
   */
  virtual ~ATerm();

  /**
   * Get the left component.
   * @return The left component.  It is never empty.
   */
  virtual std::shared_ptr<Term> getLeft() const noexcept override;

  /**
   * Get the right component.
   * @return The right component. It is never empty.
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
  /** The left component. It is never empty. */
  std::shared_ptr<Term> left_;

  /** The right component. It is never empty. */
  std::shared_ptr<Term> right_;
};

}

#endif

#ifndef HW10_TERM_H
#define HW10_TERM_H

#include <set>
#include <memory>
#include <iostream>

namespace hw10 {

class BTerm;

/**
 * A term is a node in a tree that has three kinds
 * of node: A, B and C terms.  The Term class is
 * abstract.  It has no explicit data members so
 * it is almost an interface.  However, it does
 * enable shared pointers to this, so it will have
 * the shared pointer to this as a data member.
 *
 * <p>
 *
 * The terms form a tree when only the left and
 * right components are included.  When the upper
 * links are included, the terms are a directed
 * graph which will have cycles so a memory
 * management strategy must be used.  In this case,
 * the strategy is to implement the upper links
 * using weak pointers.
 *
 * @author Ken Baclawski
 */
class Term : virtual public std::enable_shared_from_this<Term> {
public:
  /**
   * Construct a term.
   */
  Term();

  /**
   * Destructor.
   */
  virtual ~Term();

  /**
   * Print the term recursively on an output
   * stream.
   * @return The output stream
   */
  friend std::ostream& operator<<
  (/** The output stream on which to print the term. */
   std::ostream& out,
   /** The term being printed. */
   const Term& term) {
    term.print(out);
    return out;
  }

  /**
   * Get the name of the term or blank if the term
   * has no name.
   * @return The term name.
   */
  virtual std::string getName() const noexcept;

  /**
   * Get the left component.
   * @return The left component or an empty
   * pointer if there is no left component.
   */
  virtual std::shared_ptr<Term> getLeft() const noexcept;

  /**
   * Get the right component.
   * @return The right component or an empty
   * pointer if there is no right component.
   */
  virtual std::shared_ptr<Term> getRight() const noexcept;

  /**
   * Get the upper link.
   * @return The upper link or an empty pointer if
   * there is no upper link.
   */
  virtual std::shared_ptr<BTerm> getUpper() const noexcept;

  /**
   * Set the upper link.  If the upper link is
   * already set, then ignore the request to set it.
   * @throw domain_error if the parameter is empty
   * or the upper term is not an ancestor of this
   * node.
   */
  virtual void setUpper
  (/** The term that is to be the upper link. */
   std::shared_ptr<BTerm> upper);

  /**
   * Traverse the subtree at this term in
   * depth-first search manner.  A function is
   * invoked when each term is first encountered,
   * i.e., the preAction.
   */
  virtual void traverse
  (/** The function to be invoked when a term is encountered. */
   std::function<void(std::shared_ptr<Term> term)> preAction) = 0;

  /**
   * Print the term recursively on an output
   * stream.  This is the virtual function that
   * implements the output stream insertion
   * operator.
   * @return The output stream
   */
  virtual void print
  (/** The output stream on which to print the term. */
   std::ostream& out) const noexcept = 0;

private:
  // There are no explicit data members.  All data
  // members are in the subclasses of Term.
};

}

#endif

/*
 * CTerm.h
 *
 *  Created on: Apr 4, 2017
 *      Author: zeqingzhang
 */

#ifndef CTERM_H_
#define CTERM_H_
#include <set>
#include <memory>
#include <iostream>
#include "Term.h"
#include "BTerm.h"

namespace hw10 {

/**
 * This kind of term has an optional upper link to a term.
 * By default, the upper link is empty (null).
 * @author Zeqing Zhang
 * */
class CTerm : virtual public Term {
public:
	/**
	 * Construct a C term.
	 */
	CTerm();

	/**
	 * Destructor.
	 */
	 ~CTerm();

	/**
	 * Get the upper link.
	 * @return The upper link or an empty pointer if
	 * there is no upper link.
	 */
	 virtual std::shared_ptr<BTerm> getUpper() const noexcept override;

	/**
	 * Set the upper link.  If the upper link is
	 * already set, then ignore the request to set it.
	 * @throw domain_error if the parameter is empty
	 * or the upper term is not an ancestor of this
	 * node.
	 */
	virtual void setUpper(/** The term that is to be the upper link. */
	std::shared_ptr<BTerm> upper) override;

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
	   std::ostream& out) const noexcept override;


private:
	/** The optional upper link to a term. */
	std::weak_ptr<BTerm> upper_;
	};
}



#endif /* CTERM_H_ */

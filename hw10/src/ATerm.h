/*
 * ATerm.h
 *
 *  Created on: Apr 4, 2017
 *      Author: zeqingzhang
 */

#ifndef ATERM_H_
#define ATERM_H_

#include "Term.h"
#include <set>
#include <memory>
#include <iostream>

using namespace hw10;
using namespace std;

namespace hw10{

class ATerm : virtual public Term{

public:
	/*
	 * Construct ATerm with left node and right node
	 */
	ATerm(shared_ptr<Term> left, shared_ptr<Term> right);

	/*
	 * Destruct ATerm
	 */
	~ATerm();

	 /**
	   * Get the left component.
	   * @return The left component or an empty
	   * pointer if there is no left component.
	   */
		virtual shared_ptr<Term> getLeft() const noexcept override;

	  /**
	   * Get the right component.
	   * @return The right component or an empty
	   * pointer if there is no right component.
	   */
		virtual shared_ptr<Term> getRight() const noexcept override;

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
	shared_ptr<Term> left_;
	shared_ptr<Term> right_;
};







}





#endif /* ATERM_H_ */

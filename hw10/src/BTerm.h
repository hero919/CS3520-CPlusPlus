/*
 * BTerm.h
 *
 *  Created on: Apr 4, 2017
 *      Author: zeqingzhang
 */

#ifndef BTERM_H_
#define BTERM_H_

#include "Term.h"
#include <set>
#include <memory>
#include <iostream>

using namespace hw10;
using namespace std;


namespace hw10{

class BTerm : virtual public Term{

public:
	/*
	 * Construct the BTerm with three fields, name, left node and right node
	 */
	BTerm(const string& name, shared_ptr<Term> left, shared_ptr<Term> right);


	/*
	 * Destruct BTerm
	 */
	~BTerm();

 /**
   * Get the name of the term or blank if the term
   * has no name.
   * @return The term name.
   */
	virtual string getName() const noexcept override;

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
	//The left node of BTerm
	shared_ptr<Term> left_;
	//The right node of BTerm
	shared_ptr<Term> right_;
	//The name represnted as string
	const string name_;
};


}





#endif /* BTERM_H_ */

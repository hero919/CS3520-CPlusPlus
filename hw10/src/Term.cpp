/*
 * Term.cpp

 *
 *  Created on: Apr 5, 2017
 *      Author: zeqingzhang
 */

#include <set>
#include <memory>
#include <iostream>
#include "Term.h"

using namespace hw10;
using namespace std;



  /**
   * Get the name of the term or blank if the term
   * has no name.
   * @return The term name.
   */

Term::Term(){

}

Term::~Term(){

}

 std::string Term::getName() const noexcept{
	 return "";
 }
  /**
   * Get the left component.
   * @return The left component or an empty
   * pointer if there is no left component.
   */
std::shared_ptr<Term> Term::getLeft() const noexcept{
	return nullptr;
  }

  /**
   * Get the right component.
   * @return The right component or an empty
   * pointer if there is no right component.
   */
  std::shared_ptr<Term> Term::getRight() const noexcept{
	  return nullptr;
  }

  /**
   * Get the upper link.
   * @return The upper link or an empty pointer if
   * there is no upper link.
   */
std::shared_ptr<BTerm> Term::getUpper() const noexcept{
	return nullptr;
}

void Term::setUpper
 (/** The term that is to be the upper link. */
  std::shared_ptr<BTerm> upper){

}

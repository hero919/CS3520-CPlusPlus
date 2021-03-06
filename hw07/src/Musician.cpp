/*
 * Musician.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: zeqingzhang
 */

#include "Band.h"
#include "Musician.h"
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>


using namespace std;
using namespace hw07;



Musician::Musician(/** The name of the musician. */
           const std::string& name):name_(name){

}


Musician::~Musician(){
	cout << "Deleting " << name_ << endl;
}


  std::string Musician::getName() const noexcept{
	  return name_;
  }


  void Musician::add(/** The band that the musician is joining. */
           std::shared_ptr<Band> band) noexcept{
	  //If the band is null return
	  if(!band || isMember(band)){
		  return;
	  }
	  	band->add(shared_from_this());
  }


  void Musician::remove(std::shared_ptr<Band> band) noexcept{
	 band->remove(shared_from_this());
  }

  bool Musician::isMember(std::shared_ptr<Band> band) noexcept{
	  return band->hasMember(shared_from_this());
  }

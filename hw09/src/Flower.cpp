/*
 * Flower.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: zeqingzhang
 */
#include <string>

#include "Flower.h"
#include <iostream>

using namespace std;
using namespace hw09;

Flower::Flower(const string& species)
  : species_(species) {}

string Flower::getSpecies() const noexcept {
  return species_;
}




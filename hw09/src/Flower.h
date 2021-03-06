/*
 * Flower.h
 *
 *  Created on: Mar 28, 2017
 *      Author: zeqingzhang
 */

#ifndef FLOWER_H_
#define FLOWER_H_

#include <string>
using namespace std;

namespace hw09{
//Each flower has a species name
class Flower{
public:
	//Construct a flower
	Flower(/*The species name */
			const string& species);


	/**
	   * Get the name of the flower.
	   * @return The flower name.
	   */
	string getSpecies() const noexcept;


private:
	//The species field of the species
	const string species_;
};

}
#endif /* FLOWER_H_ */

/*
 * City.h
 *
 *  Created on: Mar 28, 2017
 *      Author: zeqingzhang
 */

#ifndef CITY_H_
#define CITY_H_

#include <string>
using namespace std;

namespace hw09{
//Each City has a name field.
class City{
public:
	City(/*The name of the city */
			const string& name);

	  /**
	   * Get the name of the city.
	   * @return The city name.
	   */
	string getName() const noexcept;

private:
	//Name field
	const string name_;
};


}


#endif /* CITY_H_ */

/*
 * Bijection.h
 *
 *  Created on: Mar 28, 2017
 *      Author: zeqingzhang
 */

#ifndef BIJECTION_H_
#define BIJECTION_H_


#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


namespace hw09{
// Create Template D and R
template<class D, class R>
class Bijection{
public:

	//Construct bijection
	Bijection() = default;


	//Deconstruct bijection
	~Bijection(){

	};

	//Map connect two directions between D and R and two sides map.
	void map(D object1, R object2){
		//If one of the element is null, throw domain error.
		if(!(object1 && object2)){
			throw domain_error("One of the parameter is empty");
		}

		//Insert the connection to two map
		forwardMap_.insert(std::make_pair(object1, object2));
		backwardMap_.insert(std::make_pair(object2, object1));
	}

	void forwardUnmap(D object) noexcept{
		// Unmap the Object D and two sides directions
		//Delete R->D relationship first. Because if we delete D -> R first we can't find R then
		//Loop the map
		for(auto it= backwardMap_.begin(); it!=backwardMap_.end(); ++it){
					//If find the value equals to the given object
					if(it->second == object){
						//Erase the pair
						backwardMap_.erase(it);
					}
		}
		//Then delete the D->R
		if(forwardMap_.find(object) != forwardMap_.end()){
			//Erase the pair
			forwardMap_.erase(object);
		}
	}

	void backwardUnmap(R object) noexcept{
		//Loop over the forward map
		for(auto it= forwardMap_.begin(); it!=forwardMap_.end(); ++it){
			//If found value equals to object
			if(it->second == object){
				//Erase the pair
				forwardMap_.erase(it);
			}
		}

		//If find the backmap then eraze
		if(backwardMap_.find(object) != backwardMap_.end()){
			backwardMap_.erase(object);
		}
	}

	R forward(D object) noexcept{
		//Try to find the object
		if(forwardMap_.find(object) != forwardMap_.end()){
			return forwardMap_.find(object)->second;
		}
		//If we can't the R then return null
		return nullptr;
	}

	D backward(R object) noexcept{
		//Try to find the object
		if(backwardMap_.find(object) != backwardMap_.end()){
			return backwardMap_.find(object) -> second;
		}
		//If we can't find the object, then return the null pointer
		return nullptr;
	}

private:
	//Set two multimaps two tables
	std::multimap<D,R> forwardMap_;
	std::multimap<R,D> backwardMap_;
};

}


#endif /* BIJECTION_H_ */

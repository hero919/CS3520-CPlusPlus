#include <string>
#include "Musician.h"
#include "Person.h"

using namespace std;
using namespace musician;



// Missing Code Part 6/6


Musician::Musician(/** The name of the musician. */
           const std::string& name,
	   /** The instrument played by the musician. */
	   const std::string& instrument):Person(name), instrument_(instrument){

}

std::string Musician::getInstrument() const noexcept{
	return instrument_;
}


Musician::~Musician(){

}

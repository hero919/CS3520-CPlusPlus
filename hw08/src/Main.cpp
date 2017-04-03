//============================================================================
// Name        : hw08.cpp
// Author      : Zeqing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test of People Relations
#include <boost/test/unit_test.hpp>
#include "Person.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

using namespace std;
using namespace hw08;

BOOST_AUTO_TEST_CASE (PersonRelationsTest){
	//Construct the Persons
	auto Ringo(make_shared<Person>("Ringo"));
	auto Alice(make_shared<Person>("Alice"));
	auto John(make_shared<Person>("John"));
	auto Madonna(make_shared<Person>("Madonna"));

	//Construct the relation graph
	Ringo->knows(Alice);
	Alice->knows(John);
	Alice->trusts(Madonna);
	John->trusts(Ringo);
	Madonna->trusts(Ringo);

	//Check the expection and results
	set<std::shared_ptr<Person>> RingoRelations01(Ringo->getWebOfTrust(1,1));
	BOOST_CHECK_EQUAL(RingoRelations01.size(), 2);
	BOOST_CHECK_EQUAL(RingoRelations01.find(Alice) != RingoRelations01.end(), true);
	BOOST_CHECK_EQUAL(RingoRelations01.find(Madonna) != RingoRelations01.end(), true);
	BOOST_CHECK_EQUAL(RingoRelations01.find(John) != RingoRelations01.end(), false);
	BOOST_CHECK_EQUAL(RingoRelations01.find(Ringo) != RingoRelations01.end(), false);


	set<std::shared_ptr<Person>> RingoRelations02(Ringo->getWebOfTrust(2,1));
	BOOST_CHECK_EQUAL(RingoRelations02.size(), 4);
	BOOST_CHECK_EQUAL(RingoRelations02.find(Alice) != RingoRelations01.end(), true);
	BOOST_CHECK_EQUAL(RingoRelations02.find(Madonna) != RingoRelations01.end(), true);
	BOOST_CHECK_EQUAL(RingoRelations02.find(John) != RingoRelations01.end(), true);
	BOOST_CHECK_EQUAL(RingoRelations02.find(Ringo) != RingoRelations01.end(), true);
}




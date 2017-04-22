//============================================================================
// Name        : hw10.cpp
// Author      : Zeqing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Term.h"
#include "ATerm.h"
#include "BTerm.h"
#include "CTerm.h"
using namespace std;
using namespace hw10;


int main() {
	try{
			//Construct the first graph given by the professor
			//Construct the base Term first then connect them
			auto C1(make_shared<CTerm>());
			auto C2(make_shared<CTerm>());
			auto A(make_shared<ATerm>(C1, C2));
			auto C3(make_shared<CTerm>());
			auto B1(make_shared<BTerm>("B1", A, C3));
			auto C4(make_shared<CTerm>());
			auto B2(make_shared<BTerm>("B2", B1, C4));
			C1->setUpper(B1);
			C2->setUpper(B1);
			C3->setUpper(B2);
			C4->setUpper(B2);


			cout<< *B2 <<endl;


			//Construct the second graph given by the professor
			//Construct the base Term first then connect them
			auto C11(make_shared<CTerm>());
			auto C12(make_shared<CTerm>());
			auto A1(make_shared<ATerm>(C11, C12));
			auto C13(make_shared<CTerm>());
			auto B11(make_shared<BTerm>("B1", A1, C13));
			auto C14(make_shared<CTerm>());
			auto B12(make_shared<BTerm>("B2", B11, C14));
			C11->setUpper(B11);
			C12->setUpper(B11);
			C13->setUpper(B12);
			//Here is where the error happens B1 is not the parent of C14
			C14->setUpper(B11);

			cout<<*B12 << endl;



	}catch(const exception& e){
		cout << e.what() << endl;
	}






}

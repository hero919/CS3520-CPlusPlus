#include <thread>
#include <mutex>
#include <iostream>

#include "Huffman.h"

using namespace std;
using namespace chrono;
using namespace hw06;

/**
 * @namespace hw06 Huffman coding algorithm with
 * multi-threading.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for multi-threaded Huffman decoding.
 * @return The status code.  Normal is 0.
 * @throws domain_error if there is no training
 * data.
 */
int main() {

  // Train the Huffman coder
try{
  string trainingData;
  getline(cin, trainingData);
  if (!cin || trainingData == "quit") {
    throw domain_error("There was no training data");
  }
  Huffman coder(trainingData);

  // The thread procedure reads a line from the
  // standard input, decodes the line and prints
  // the decoded text.

    // Fill in the missing code...
  std::mutex readLock;
  std::mutex writeLock;

  int count = 0;
    // Run three threads

string input;
 auto task =  [&](){
	 //Create a unique lock
	 unique_lock<mutex> lockForRead(readLock);
	 //Get the input
	 getline(cin, input);
	 //If there is no input, then return
	 if(input.length() == 0){
		 lockForRead.unlock();
		 return;
	 }

	 //If there is an input increment the count by one and also unlock the read
	 count++;
	 lockForRead.unlock();
	 //Output the decode result
	 string output = coder.decode(input);
	 cout << output<< endl;
 };


 //Run three threads

  thread first(task);
  thread second(task);
  thread third(task);



    // Wait for the threads to finish
  first.join();
  second.join();
  third.join();

  if(count < 3){
  	cout<<"No more input" << endl;
  }



    // Normal completion
}catch(std::exception& e){
	//Try to catch the exception during the running process
	std::cout << "MyException caught" << std::endl;
	std::cout << e.what() << std::endl;
}

  return 0;
}


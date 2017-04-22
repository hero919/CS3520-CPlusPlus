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

  string trainingData;
  getline(cin, trainingData);
  if (!cin || trainingData == "quit") {
    throw domain_error("There was no training data");
  }
  Huffman coder(trainingData);

  // The lockable object

  mutex lockableObject;

  // The thread procedure

  auto threadProcedure = [&coder,&lockableObject](){

    // Set the lock

    lock_guard<mutex> lock(lockableObject);

    // Read a line and check if done

    string encodedData;
    getline(cin, encodedData);
    if (!cin || encodedData == "quit") {
      cout << "No more input" << endl;
      return;
    }

    // Decode the encoded data and print it.

    try {
      cout << coder.decode(encodedData) << endl;
    } catch (const exception& e) {
      cout << "Invalid input" << endl;
    }
  };

  // Run three threads

  thread t1(threadProcedure);
  thread t2(threadProcedure);
  thread t3(threadProcedure);

  // Wait for them to finish

  t1.join();
  t2.join();
  t3.join();

  // Normal completion

  return 0;
}

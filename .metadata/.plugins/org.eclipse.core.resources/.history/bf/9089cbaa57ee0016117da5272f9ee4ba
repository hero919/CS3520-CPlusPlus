//============================================================================
// Name        : hw04.cpp
// Author      : Zeqing
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdexcept>
#include <iostream>
#include "BinaryTree.h"
using namespace std;
using namespace hw04;
/**
 * @namespace hw04 Binary trees. These are also
 * known as Lisp lists.
 *
 * @author Ken Baclawski
 */
/**
 * Main program for testing binary trees.
CS3520 Programming in C++ Spring 2017
 * @return The exit status. Normal status is 0.
 */
int main() {
 try {
 // Create a binary tree.
 const BinaryTree a("A", 4);
 const BinaryTree b("B", 2);
 const BinaryTree c("C", 2);
 const BinaryTree d("D", 2);
 const BinaryTree e("E", 7);
 const BinaryTree bc(b, c);
 const BinaryTree ad(a, d);
 const BinaryTree abcd(ad, bc);
 const BinaryTree top(abcd, e);
 // Print the tree.
 top.printTree(cout);
 cout << endl;
 // Look up some text in the binary tree.
 string path("ADDDAADD");
 for (auto iter = path.begin(); iter < path.end(); ) {
 cout << top.get(iter, path.end());
 }
 cout << endl;
 } catch (const domain_error& error) {

 // Show the error.
 cout << error.what() << endl;
 return 1;
 }
 // Normal return
 return 0;
}

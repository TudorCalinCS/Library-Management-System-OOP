#include <iostream>
#include "Ui.h"
/**
 * Library Management System - An OOP Project
 *
 * This C++ project is a proof of concept for object-oriented programming (OOP) principles. It showcases how OOP concepts like encapsulation, abstraction, inheritance, and polymorphism are applied to create a Library Management System.
 *
 * Author: Tudor-Calin
 * Date: 19/10/2023
 */
int main() {
	//Create instances of repositories for books and users
	BookRepository bookRepository;
	UserRepository userRepository;
	
	//Create a Service object to manage the core functionality
	Service service{ bookRepository,userRepository };
	
	//Create a Ui object to provide a user interface
	Ui ui{ service };
	
	//Start the user interaction
	ui.start();
	
	//Indicates succesful program execution
	return 0;
}

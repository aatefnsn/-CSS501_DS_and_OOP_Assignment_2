#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class Book {
private:

	int numberOfPages;  
	string bookName;
	
public: 
	Book(); // empty constructor 
	Book(int num, string name);
	~Book(); // destructor
	int getNumberOfPages() ; //getter
	string getName() const; // getter
	bool setNumberOfPages(int num); // setter
	bool setName(string name); //setter 
	void printBook(); // printing book 
};
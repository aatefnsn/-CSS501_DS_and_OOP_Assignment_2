#include "pch.h"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

	Book::Book() { // empty Book Constructor
		setNumberOfPages(0);
		setName("");

	}

	Book::Book(int num, string name) { // Book Constructor
		setNumberOfPages(num);
		setName(name);
	}

	Book::~Book() { // destructor
		//cout << "Book is being deleted" << endl;
	}

	bool Book::setNumberOfPages(int num) { // applying invariants in the setter 
		if (num <= 0) // if number of pages is 0 or -ve .. make it 0
			this->numberOfPages = 0;
		else
			this->numberOfPages = num; 

		return true;
	}

	bool Book::setName(string name) { // applying invariants in the setter 
		if (name == "")
			this->bookName = "";
		else
			this->bookName = name; 

		return true; 
	}

	int Book::getNumberOfPages() {
		return this->numberOfPages; 
	}

	string Book::getName() const {
		return this->bookName;
	}

	void Book::printBook() {
		cout << "The book name is " << this->getName() << " and has " << this->getNumberOfPages() << " pages" << endl;
	}


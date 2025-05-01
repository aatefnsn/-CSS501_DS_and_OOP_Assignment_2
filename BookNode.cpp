#include "pch.h"
#include <stdio.h>
#include <iostream>
using namespace std;

BookNode::BookNode(Book * b, BookNode* n, BookNode* p) { // booknode constructor 
	this->b = b; 
	this->next = n;
	this->previous = p;
}

BookNode::BookNode(Book * b) { // booknode constructor 
	this->b = b;
	this->next = NULL;
	this->previous = NULL;
}

BookNode::BookNode() { // booknode empty constructor 
	this->b = NULL;
	this->next = NULL;
	this->previous = NULL;
}
BookNode::~BookNode() { // destructor 
}


Book * BookNode::getBook() {  // getter 
	return this->b;
}

void BookNode::printBookNode() {// print method 
	this->b->printBook();
}
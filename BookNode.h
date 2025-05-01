#pragma once
#include "Book.h"

class BookNode {
public:
	Book * b;
	BookNode* next;
	BookNode* previous;

	BookNode(Book * b, BookNode* n, BookNode* p); 
	BookNode(Book * b);
	BookNode();
	~BookNode();
	Book * getBook();
	void printBookNode();
};


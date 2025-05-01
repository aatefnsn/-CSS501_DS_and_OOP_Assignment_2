#pragma once
#include "BookNode.h"


class BookList {
public:
	BookNode* head;
	BookNode* tail;
	BookList(); // empty constructor
	~BookList(); // destructor
	BookList(BookNode* node);
	void push_back(BookNode* node); // push back a node into a list
	void push_back(int pages, string name); // push back using book details 
	Book pop(); // pop method to remove amd return the tail of the list 
	void swap(BookNode* node1, BookNode* node2); // swapping two nodes
	void bubblesort(); // bubble sort descending
	void bubblesortAscending(); // bubble sort ascending 
	void PrintList(); // print list
	int search(string str); // search method 
};
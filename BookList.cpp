#include "pch.h"
#include <string>
using namespace std;
BookList::BookList() // empty constructor seting head and tail to NULL
{
	head = NULL;
	tail = NULL;	
}

BookList::~BookList() // destructor to delete the book list node by node 
{
	BookNode * current;
	current = this->head;
	while (current != NULL) {
		BookNode * next = current->next;
		delete current->getBook(); // delete book 
		delete current; // delete node 
		current = next;
	}
}

BookList::BookList(BookNode* node) // constructor 
{
	this->head = node;
	this->tail = node;
}

void BookList::push_back(BookNode* node) { // push back takes a pointer to node 

	if (this->head == NULL || this->tail == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		this->tail->next = node; // updating pointers
		node->previous = this->tail;
		this->tail = node; // updating tail to point to last added node
	}
}

void BookList::push_back(int pages, string name) { // push back that takes book details and created a book node pointer
	// TODO: error check to make sure node is not null
	Book * x = new Book(pages, name);
	BookNode * bNode = new BookNode(x); 
	push_back(bNode);
}


Book BookList::pop() { // Removes the last thing that was put in (i.e. remove the tail)
	
	this->tail = this->tail->previous; // set the previous node before tail to be the new tail
	Book  * dataToReturn = this->tail->next->b; // keep track of the value to return
	this->tail->next = NULL; // change the tail-> next to null
	return *dataToReturn; // return the value that's being popped
}

void BookList::swap(BookNode* node1, BookNode* node2) { // swapping function, i thought it is better to swap the books rather than swapping the pointers
	// the below lines will swap the pointers perfectly fine but i thought it is better to only swap the data
	//if (node1->previous == NULL)		
	//	this->head = node2;
	//if (node2->previous == NULL)
	//	this->head = node1;
	//if (node2->next == NULL)
	//	this->tail = node1; 
	//if (node1->next == NULL)
	//	this->tail = node2;
	BookNode temp = BookNode();
//	temp.next = node1->next; // putting node1 fields in a temp
//	temp.previous = node1->previous;
	temp.b = node1->getBook();
//	node1->next = node2->next; // swapping the nodes pointers
//	node1->previous = node2->previous;
	node1->b = node2->getBook();
//	node2->next = temp.next;
//	node2->previous = temp.previous;
	node2->b = temp.b; 
	//if (node1->next != NULL)
	//	node1->next->previous = node1;
	//if (node1->previous != NULL)
	//	node1->previous->next = node1; 
	//if (node2->next != NULL)
	//	node2->next->previous = node2; 
	//if (node2->previous != NULL)
	//	node2->previous->next = node2;	
}
void BookList::bubblesort() { // bubbule sort algorithm 
	if (head == NULL || head->next == NULL) {
		return;
	}
	bool flag = true;
	while (flag == true)
	{
		flag = false; // flag to false to reset 
		BookNode * current = this->head;
		BookNode * next = current->next;
		while (next != NULL) {
			if (current->b->getNumberOfPages() < next->b->getNumberOfPages())
			{
				swap(current, next);
				flag = true; // set flag to true if swapped occured 
			}
			current = current->next; // move runner pointers 
			next = next->next;
		}

	}
}

void BookList::bubblesortAscending() { // same as descending algorith only switching comparison operator
	if (head == NULL || head->next == NULL) {
		return;
	}
	bool flag = true;
	while (flag == true)
	{
		flag = false;
		BookNode * current = this->head;
		BookNode * next = current->next;
		while (next != NULL) {
			if (current->b->getNumberOfPages() > next->b->getNumberOfPages())
			{
				swap(current, next);
				flag = true;
			}
			current = current->next;
			next = next->next;
		}
	}
}

void BookList::PrintList() { // printing the list by going over the nodes and printing the booknode 
	BookNode * current ; 
	current = this->head;
	while (current != NULL) {
		current->printBookNode();		
		current = current->next;
	}
}

int BookList::search(string str) { // Search Function is Big-O of (n) since it traverses the whole list to search for the element 
	int counter = 0; 	
	BookNode * current;
	current = this->head;
	while (current != NULL) {
		string name = current->getBook()->getName();
		if ((name.compare(str)) ==0) { // comparing the strings 
			return counter;
		}
		current = current->next;
		counter++;
	}
	return -1; // return -1 if string is not found 
}
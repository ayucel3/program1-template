#ifndef _LIST_H_
#define _LIST_H_

#include "Planet.h"

class Node{
public:
	Planet * data;
  	Node * next;
  	Node * prev;

  	Node(Planet * num);
};

class List{
private:
	Node *head, *tail;
	int listSize;
	
public:
	List();
	~List();
	void planetbyOrbit();
	void insert(int, Planet*);
	Planet* read(int);
	Planet* readbyID(int);
	bool remove(int);
	bool removebyID(int);
	unsigned size();
	void printInfo();
};

#endif

#ifndef _LIST_H_
#define _LIST_H_

#include "Planet.h"
#include "Star.h"

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
	void insert(int, Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
};

#endif

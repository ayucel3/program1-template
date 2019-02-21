#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include "Planet.h"

class Node{
public:
	Planet * data;
  	Node * next;

  	Node();
  	Node(Planet * num)
};

class List{
private:
	Node *head, *tail;
	
public:
	List();
	~List();
	void insert(int, Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
}

#endif

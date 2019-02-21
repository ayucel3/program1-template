#include <iostream>
#include "List.h"

Node::Node(Planet * p)
{
	this -> data = p; 
	this -> next = NULL;
	this -> prev = NULL;
}


List::List()
{
	this -> head = NULL;
	this -> tail = NULL;
	this -> listSize = 0;
}

List::~List()
{
	Node *p = head;
	while (head->next != NULL)
	{
		p = head ->next;
		delete head;
		head = p;
		listSize--;
	}
	delete head;
}

void List::insert(int index, Planet * p)
{
	p->setID( (long int)p );
	Node * node = new Node(p);
	if (index == 0) {
		if (this->head != NULL) {
			node->next = this->head;
			this->head->prev = node;
			this->head = node;
		} else {
			this->head = node;
			this->tail = node;
		}
		this->listSize++;
		return;
	} 
	if (index >= this->listSize) {
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	} else {
		Node * tmp = this->head;
		for (int i = 0; i < index-1; i++) {
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next->prev = node;
		tmp->next = node;
		node->prev = tmp;
	}
	this->listSize++;
}


Planet * List::read(int index)
{
	Node * current = this->head;
	for (int i =0; i < index; i++)
	{
		if (current -> next != NULL)
		{
			current = current -> next;
		}
		else
		{
			return NULL;
		}
	}
	return current -> data;
}

bool List::remove(int index)
{
	int i = 0;
	Node * dummy = new Node(new Planet(0));
	dummy->next = head;
	head->prev = dummy;

	Node * current  = dummy;
	while (current->next != NULL)
	{
		if (i == index)
		{	
			Node * temp = current -> prev;
			temp -> next = current -> next;
			current -> next -> prev = temp;
			delete current;
			listSize--;
			this -> head -> prev = NULL;
			delete dummy;
			return true;
		}
		current = current -> next;
		i++;
		if (i > index)
		{
			this -> head -> prev = NULL;
			delete dummy;
			return false;
		}		
	}
}

unsigned List::size() {return this -> listSize;}

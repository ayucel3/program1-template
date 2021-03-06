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

Planet * List::readbyID(int ID)
{
	int i=0;
	Node * current  = head;
	while (current->next != NULL)
	{
		if (current->data->getID() == ID)
		{
			return read(i);	
		}
	i++;
	current = current->next;
	}
	return NULL;
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
boold List::removebyID(int ID)
{	
	int i=0;
	Node * current  = head;
	while (current->next != NULL)
	{
		if (current->data->getID() == ID)
		{
			return remove(i);	
		}
	i++;
	current = current->next;
	}
	return false;
}
void List::planetOrbit()
{
	Node * current  = head;
	while (current->next != NULL)
	{
		current->data->orbit();
		current = current->next;
	}	
}
void List::printInfo()
{
	Node * current  = head;
	while (current->next != NULL)
	{
		current->data->printPlanetInfo();
		current = current->next;
	}
}
bool List::remove(int index)
{
	int i = 0;
	Node * current  = head;
	while (current->next != NULL)
	{
		if (index == 0)
		{
			Node * temp = head->next;
			head->next = current;
			current->next = temp;
			delete head;
			head = temp;
			listSize--;
			return true;
		}
		if (i == index)
		{	
			current->prev->next = current->next;
			current->next = current->prev;
			delete current;
			listSize--;
			return true;
		}
		current = current -> next;
		i++;
		if (i > index)
		{
			this -> head -> prev = NULL;
			return false;
		}		
	}
	return false;
}

unsigned List::size() {return this -> listSize;}


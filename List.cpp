#include <iostream>
#include "List.h"

Node::Node(Planet * ID)
{
	this -> data =num; 
	this -> next;
	this -> prev;
}

List::List()
{
	this -> head = NULL;
	this -> tail = NULL;
	size = 0;
}

List::~List()
{
	Node *p = head;
	while (head->next != NULL)
	{
		p = head ->next;
		delete head;
		head = p;
		size--;
	}
}

void insert(int index, Planet * p)
{
	Node * current = head;
	int i =0;
	if
	{
		tail->next = new Node(*p);
		*p -> next = tail;
		size++;
		return;
	}
	while (current->next != NULL)
	{
		
		if (i == index)
		{
			current -> next = new Node(*p);
			*p -> next = current ->next -> next;
			size++;
			return;
		}
	i++;
	current = current -> next;
	}
}

Planet * List::read(int index)
{
	Node * current = head;
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
	return current -> data;


}

bool List::remove(int index)
{
	Node * current = head;
	int i =0;
	while (current->next != NULL)
	{
		if (i == index)
		{	
			Node * temp = current -> prev;
			current -> prev = current -> next;
			current -> next -> temp;
			delete[] current;//I dont know if it delets all
			size--;
			return true;
		}
		current = current -> next;
		if (i > index)
		{
			
			return false;
		}
		i++;
	}
}

unsigned List::size(){return this -> size;}

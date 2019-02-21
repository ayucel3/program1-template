#include <iostream>
class Node{
public:
  Node();
  Planet * data;
  Node * next;
  Node(Planet * num)
};
}
class List{
private:
	Node *head,*tail;
public:
	List();
	~List();
	void insert(int, Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned size();
}

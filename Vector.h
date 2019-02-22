#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Planet.h"

class Vector {
private:
	int cap;         // capacity
	Planet ** planets;

public:
	Vector();
	~Vector();
	void insert(int index, Planet * p);
	Planet* read(int index);
	bool remove(int index);
	unsigned int size() {return this->cap;};
};

#endif
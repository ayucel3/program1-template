#include "Vector.h"
#include <cstdlib> 

Vector::Vector() {
	this->cap = 0;
}

Vector::~Vector() {
	for (int i = 0; i < this->cap; i++) {
		delete this->planets[i];
	}
	delete[] this->planets;
}

void Vector::insert(int index, Planet * p) {
	p->setID( (long int)p );
	Planet ** newList;
	if (index >= this->cap) {
		newList = new Planet*[index + 1];
		for (int i = 0; i < this->cap; i++) {
			newList[i] = this->planets[i];
		}
		for (int i = this->cap; i <= index; i++) {
			newList[i] = NULL;   // Initialize to NULL, before using it
		}
		newList[index] = p;
		this->cap = index + 1;
	} else {
		newList = new Planet*[this->cap + 1];
		for (int i = 0; i < index; i++) {
			newList[i] = this->planets[i];
		}
		for (int i = index; i < this->cap; i++) {
			newList[i + 1] = this->planets[i];
		}
		newList[index] = p;
		this->cap++;
	}
	// Free memory and updata
	delete[] this->planets;
	this->planets = newList;
}

Planet* Vector::read(int index) {
	Planet * res = NULL;
	if (index < this->cap) res = this->planets[index];
	return res;
}

bool Vector::remove(int index) {
	if (index >= this->cap) return false; 
	Planet ** newList = new Planet*[this->cap - 1];
	for (int i = 0; i < index; i++) {
		newList[i] = this->planets[i];
	}
	for (int i = index + 1; i < this->cap; i++) {
		newList[i - 1] = this->planets[i];
	}
	delete[] this->planets;
	this->planets = newList;
	this->cap--;
	return true;
}
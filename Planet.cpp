#include "Planet.h"
#include <iostream>

Planet::Planet(int distance) {
	char type[3] = {'h', 'r', 'g'};
	this->distance = distance % 3000;
    this->pos = rand() % 360;
    this->type = type[rand() % 3];
}

int Planet::orbit() {
	int tmp = this->pos + 1;
	this->pos = (tmp > 359) ? 0 : tmp;
	return this->pos;
}

void Planet::printPlanetInfo() {
	std::cout << "Planet " << this->type << this->id << " is " << this->distance << " million miles away ";
	std::cout << "at position " << this->pos << " around the star." << std::endl;
}
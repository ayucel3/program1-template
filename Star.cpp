#include "Star.h"
#include <iostream>


// Implementation for Star
																																																																																		
Star::Star() {
	this->planets = NULL;
	this->current = 0;
	this->nextId = 0;
}

Star::~Star() {
	for (int i = 0; i < this->current; i++) {
		delete this->planets[i];
	}
	delete[] this->planets;
}

int Star::addPlanet() {
	// Create and add new planet
	Planet ** newList = new Planet*[this->current + 1];
	for (int i = 0; i < this->current; i++) {
		newList[i] = this->planets[i];
	}
	int distance = rand();
	Planet * p = new Planet(distance);
	newList[this->current] = p;

	// Free old array
	delete[] this->planets;

	// Update
	this->planets = newList;
	this->current++;
	this->nextId++;
	return p->getID();
}

bool Star::removePlanet(int id) {
	int targetIdx = -1;
	for (int i = 0; i < this->current; i++) {
		if (this->planets[i]->getID() == id) {
			targetIdx = i;
			break;
		}
	}
	if (targetIdx == -1) return false;
	
	// Creat new list
	Planet ** newList = new Planet*[this->current - 1];
	for (int i = 0, j = 0; i < this->current; i++) {
		if (i == targetIdx) continue;
		newList[j] = this->planets[i];
		j++;
	}

	// Free memory
	delete this->planets[targetIdx];
	delete[] this->planets;

	//Update
	this->planets = newList;
	this->current--;
	return true;
}


Planet * Star::getPlanet(int id) {
	Planet * p = NULL;
	for (int i = 0; i < this->current; i++) {
		if (this->planets[i]->getID() == id) {
			p = this->planets[i];
			break;
		}
	}
	return p;
}


void Star::orbit() {
	for(int i = 0; i < this->current; i++) {
		this->planets[i]->orbit();
	}
}


void Star::printStarInfo() {
	std::cout << "\tThe star has " << this->current << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(int i = 0; i < this->current; i++) {
		std::cout << "\t";
		this->planets[i]->printPlanetInfo();
	}
}









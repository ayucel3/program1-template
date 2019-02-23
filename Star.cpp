#include "Star.h"
#include <iostream>


// Implementation for Star
																																																																																		
Starlist::Starlist() {
	//this->planets = NULL;
	//this->current = 0;
	//this->nextId = 0;
	
}

Starlist::~Starlist() { delete palents;}

int Starlist::addPlanet() {
	// Create and add new planet
	int distance = rand();
	Planet * p = new Planet(distance);
	insert(0,p);
	return p->getID();
}

bool Starlist::removePlanet(int id) {
	return planets->removebyID(id);
}


Planet * Starlist::getPlanet(int id) {
	return planets->readbyID(id);
}

void Starlist::planetOrbit(){
	planets->planetbyOrbit();	
}
void Starlist::orbit() {
	for(int i = 0; i < this->current; i++) {
		this->planets[i]->orbit();
	}
}


void Starlist::printStarInfo() {
	std::cout << "\tThe star has " << planets->size(); << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	planets->printInfo();
}








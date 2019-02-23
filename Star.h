#ifndef _STAR_H_
#define _STAR_H_
#include "Planet.h"
#include "List.h"



class Starlist{
private:
	List * planets;
public:
	Starlist(){planets = new List();};
	~Starlist();
	long addPLanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets(){return planets->size();
};
#endif

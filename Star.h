#ifndef _STAR_H_
#define _STAR_H_
#include "Planet.h"


class Star{
private:
        int current;
        int nextId;
        
public:
        Planet ** planets;
        Star();
        ~Star();
        int addPlanet();
        bool removePlanet(int);
        Planet * getPlanet(int);
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets() {return this->current;};
};

#endif

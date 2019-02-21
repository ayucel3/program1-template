#ifndef _PLANET_H_
#define _PLANET_H_


class Planet{
private:
	long int id;
	int pos;
	int distance;
	char type;
public:
	Planet() {};
	Planet(int);
    int orbit();
    void setID(long int id) { this->id = id;};
	long int getID() {return this->id;};
    int getDistance() {return this->distance;};
    int getPos() {return this->pos;};
    char getType() {return this->type;};
	void printPlanetInfo();
};

#endif
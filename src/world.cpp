#include <iostream>
#include <istream>
#include <string>

#include "world.hpp"

using namespace std;

std::string World::getWorldName() const{
	return WorldName;
}

void World::setWorldName(std::string n){
	if (n.length() == 0)
		WorldName = "Nome não definido";
	else
		WorldName = n;
}

std::string World::getWorldColor() const{
	return WorldColor;
}

void World::setWorldColor(std::string c){
	if (c.length() == 0)
		WorldName = "Cor não definida";
	else
		WorldColor = c;
}

int World::getWorldPopulation() const{
	return WorldPopulation;
}

void World::setWorldPopulation(int p){
	if (p < 0)
		WorldPopulation = 0;
	else
		WorldPopulation = p;
}
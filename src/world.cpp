#include <iostream>
#include <istream>
#include <string>

#include "world.hpp"
#include "list.hpp"

using namespace std;

void World::setWorldProfile (World& www, int cc){
	std::string val, vall;
	int vau;
	std::cout << "\n>> Qual o nome do mundo " << cc << "?" << std::endl;
	std::cin.ignore();
	std::getline (std::cin, val);
	www.setWorldName(val);
	std::cout << ">> Qual a cor da atmosfera do mundo " << cc << "?" << std::endl;
	std::getline (std::cin, vall);
	www.setWorldColor(vall);
	std::cout << ">> Qual a quantidade de habitantes do mundo informado?" << std::endl;
	cin >> vau;
	www.setWorldPopulation(vau);
}

void World::showWorldProfile (const World& www, int cc){
	std::cout << ">> O nome do mundo " << cc << " é: " << www.getWorldName() << std::endl;
	std::cout << ">> A cor da atmosfera do mundo " << cc << " é: " << www.getWorldColor() << std::endl;
	std::cout << ">> A quatidade de habitantes é: " << www.getWorldPopulation() << std::endl;
}

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
		WorldColor = "Cor não definida";
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
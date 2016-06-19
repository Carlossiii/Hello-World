#ifndef BLABLA_HPP
#define BLABLA_HPP

#include <iostream>

class World{
private:
	std::string WorldName;
	std::string WorldColor;
	int WorldPopulation;
public:
	std::string getWorldName() const;
	void setWorldName(std::string);
	std::string getWorldColor() const;
	void setWorldColor(std::string);
	int getWorldPopulation() const;
	void setWorldPopulation(int);
};

#endif
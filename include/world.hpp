#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
#include <istream>
#include <string>

using namespace std;

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

	void setWorldProfile (World&, int cc);
	void showWorldProfile (const World&, int cc);
};

#endif
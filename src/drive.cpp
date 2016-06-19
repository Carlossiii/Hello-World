#include <iostream>
#include <istream>
#include <string>

#include "world.hpp"

using namespace std;

void setWorldProfile (World&, int cc);
void showWorldProfile (const World&, int cc);

int main (int argc, char * argv[]){
	std::string input;
	int m, c=1;
	if (argc == 2){
		input = (std::string)argv[1];
		std::cout << ">>> Hello " << input << "!"<< std::endl;
		std::cout << "\n>>> Quantos mundos você quer criar?" << std::endl;
		cin >> m;
		while (c <= m){
			World wc;
			setWorldProfile (wc, c);
			std::cout << "\n>>> Mostrando mundo criado:" << std::endl;
			showWorldProfile (wc, c);
			c++;
		}
	}
	else
		cout << ">>> Erro. Tente: $ ./bin/teste [Seu_Nome]\n";
	return 0;
}

void setWorldProfile (World& www, int cc){
	std::string val;
	int vau;
	std::cout << "\n>> Qual o nome do mundo " << cc << "?" << std::endl;
	std::cin.ignore();
	std::getline (std::cin, val);
	www.setWorldName(val);
	std::cout << ">> Qual a cor da atmosfera do mundo " << cc << "?" << std::endl;
	std::getline (std::cin, val);
	www.setWorldColor(val);
	std::cout << ">> Qual a quantidade de habitantes do mundo informado?" << std::endl;
	cin >> vau;
	www.setWorldPopulation(vau);
}

void showWorldProfile (const World& www, int cc){
	std::cout << ">> O nome do mundo " << cc << " é: " << www.getWorldName() << std::endl;
	std::cout << ">> A cor da atmosfera do mundo " << cc << " é: " << www.getWorldColor() << std::endl;
	std::cout << ">> A quatidade de habitantes é: " << www.getWorldPopulation() << std::endl;
}
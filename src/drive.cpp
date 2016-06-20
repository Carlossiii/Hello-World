#include <iostream>
#include <istream>
#include <string>

#include "world.hpp"
#include "list.hpp"

using namespace std;

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
			wc.setWorldProfile (wc, c);
			std::cout << "\n>>> Mostrando mundo criado:" << std::endl;
			wc.showWorldProfile (wc, c);
			c++;
		}
	}
	else
		cout << ">>> Erro. Tente: $ ./bin/teste [Seu_Nome]\n";
	return 0;
}
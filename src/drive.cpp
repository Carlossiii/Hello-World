#include <iostream>
#include <string>

using namespace std;

class World{
public:
	std::string WorldName;
	std::string color;
	int population;
};

void getWorldProfile (World&);
void showWorldProfile (const World&);

int main (int argc, char * argv[]){
	World w1;
	std::string input;
	if (argc == 2){
		input = (std::string)argv[1];
		std::cout << input << std::endl;
	}
	else{
		getWorldProfile (w1);
		std::cout << "Mostrando mundo criado:" << std::endl;
		showWorldProfile (w1);
		//std::cout << "Hello World" << std::endl;
	}
	return 0;
}

void getWorldProfile (World& www){
	std::cout << "Qual o nome do mundo?" << std::endl;
	std::getline (std::cin, www.WorldName);
	std::cout << "Qual a cor da atmosfera do mundo?" << std::endl;
	std::getline (std::cin, www.color);
	std::cout << "Qual a quantidade de habitantes do mundo informado?" << std::endl;
	cin >> www.population;
}

void showWorldProfile (const World& www){
	std::cout << "O nome do mundo é: " << www.WorldName << std::endl;
	std::cout << "A cor da atmosfera do mundo é: " << www.color << std::endl;
	std::cout << "A quatidade de habitantes é: " << www.population << std::endl;
}
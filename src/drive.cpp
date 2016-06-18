#include <iostream>
#include <string>

using namespace std;

int main (int argc, char * argv[]){
	std::string input;
	if (argc == 2){
		input = (std::string)argv[1];
		std::cout << input << std::endl;
	}
	else{
		std::cout << "Hello World" << std::endl;
	}
	return 0;
}
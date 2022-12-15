#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "prisoners.h"
#include "strats.h"


int main() {
	std::vector<Prisoner*> pr;

	char choice;
	char n;
	std::cout << "Welcome!" << std::endl << "Choose mode: Detailed D, Fast F, Tournament T" << std::endl;
	std::cin >> choice;

	if (toupper(choice) == 'D')
		detailed();
	else if (toupper(choice) == 'F')
	{
		std::cout << "Enter quantity of steps" << std::endl;
		scanf("%c", &n);
		scanf("%c", &n);
		while (!isdigit(n))
		{
			std::cout << "Enter quantity of steps" << std::endl;
			scanf("%c", &n);
			scanf("%c", &n);
		}
		fast(int(n)-'0');
	}
		
	else if (toupper(choice) == 'T')
	{
		std::cout << "Enter quantity of steps" << std::endl;
		scanf("%c", &n);
		scanf("%c", &n);
		while (!isdigit(n))
		{
			std::cout << "Enter quantity of steps" << std::endl;
			scanf("%c", &n);
			scanf("%c", &n);
		}
		tournament(int(n) - '0');
	}
		
	else
		std::cout << "No option found. See you next time looser"<<std::endl;
	return 0;
}

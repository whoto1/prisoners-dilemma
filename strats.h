#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include"prisoners.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

//#include <memory>
void get_score(std::vector<Prisoner*> contestants)
{
	if (contestants[0]->get_move() == 'C' && contestants[1]->get_move() == 'C' && contestants[2]->get_move() == 'C') {
		contestants[0]->score_update(7);
		contestants[1]->score_update(7);
		contestants[2]->score_update(7);
	}
	else if (contestants[0]->get_move() == 'C' && contestants[1]->get_move() == 'C' && contestants[2]->get_move() == 'D')
	{
		contestants[0]->score_update(3);
		contestants[1]->score_update(3);
		contestants[2]->score_update(9);
	}
	else if (contestants[0]->get_move() == 'C' && contestants[1]->get_move() == 'D' && contestants[2]->get_move() == 'C')
	{
		contestants[0]->score_update(3);
		contestants[1]->score_update(9);
		contestants[2]->score_update(3);
	}
	else if (contestants[0]->get_move() == 'D' && contestants[1]->get_move() == 'C' && contestants[2]->get_move() == 'C')
	{
		contestants[0]->score_update(9);
		contestants[1]->score_update(3);
		contestants[2]->score_update(3);
	}
	else if (contestants[0]->get_move() == 'C' && contestants[1]->get_move() == 'D' && contestants[2]->get_move() == 'D')
	{
		contestants[0]->score_update(0);
		contestants[1]->score_update(5);
		contestants[2]->score_update(5);
	}
	else if (contestants[0]->get_move() == 'D' && contestants[1]->get_move() == 'C' && contestants[2]->get_move() == 'D')
	{
		contestants[0]->score_update(5);
		contestants[1]->score_update(0);
		contestants[2]->score_update(5);
	}
	else if (contestants[0]->get_move() == 'D' && contestants[1]->get_move() == 'D' && contestants[2]->get_move() == 'C')
	{
		contestants[0]->score_update(5);
		contestants[1]->score_update(5);
		contestants[2]->score_update(0);
	}
	else if (contestants[0]->get_move() == 'D' && contestants[1]->get_move() == 'D' && contestants[2]->get_move() == 'D')
	{
		contestants[0]->score_update(1);
		contestants[1]->score_update(1);
		contestants[2]->score_update(1);
	}
}
void get_score_tourn(std::vector<Prisoner*> contestants, int* a)
{
	if (contestants[a[0] - 1]->get_move() == 'C' && contestants[a[1] - 1]->get_move() == 'C' && contestants[a[2] - 1]->get_move() == 'C') {
		contestants[a[0] - 1]->score_update(7);
		contestants[a[1] - 1]->score_update(7);
		contestants[a[2] - 1]->score_update(7);
	}
	else if (contestants[a[0] - 1]->get_move() == 'C' && contestants[a[1] - 1]->get_move() == 'C' && contestants[a[2] - 1]->get_move() == 'D')
	{
		contestants[a[0] - 1]->score_update(3);
		contestants[a[1] - 1]->score_update(3);
		contestants[a[2] - 1]->score_update(9);
	}
	else if (contestants[a[0] - 1]->get_move() == 'C' && contestants[a[1] - 1]->get_move() == 'D' && contestants[a[2] - 1]->get_move() == 'C')
	{
		contestants[a[0] - 1]->score_update(3);
		contestants[a[1] - 1]->score_update(9);
		contestants[a[2] - 1]->score_update(3);
	}
	else if (contestants[a[0] - 1]->get_move() == 'D' && contestants[a[1] - 1]->get_move() == 'C' && contestants[a[2] - 1]->get_move() == 'C')
	{
		contestants[a[0] - 1]->score_update(9);
		contestants[a[1] - 1]->score_update(3);
		contestants[a[2] - 1]->score_update(3);
	}
	else if (contestants[a[0] - 1]->get_move() == 'C' && contestants[a[1] - 1]->get_move() == 'D' && contestants[a[2] - 1]->get_move() == 'D')
	{
		contestants[a[0] - 1]->score_update(0);
		contestants[a[1] - 1]->score_update(5);
		contestants[a[2] - 1]->score_update(5);
	}
	else if (contestants[a[0] - 1]->get_move() == 'D' && contestants[a[1] - 1]->get_move() == 'C' && contestants[a[2] - 1]->get_move() == 'D')
	{
		contestants[a[0] - 1]->score_update(5);
		contestants[a[1] - 1]->score_update(0);
		contestants[a[2] - 1]->score_update(5);
	}
	else if (contestants[a[0] - 1]->get_move() == 'D' && contestants[a[1] - 1]->get_move() == 'D' && contestants[a[2] - 1]->get_move() == 'C')
	{
		contestants[a[0] - 1]->score_update(5);
		contestants[a[1] - 1]->score_update(5);
		contestants[a[2] - 1]->score_update(0);
	}
	else if (contestants[a[0] - 1]->get_move() == 'D' && contestants[a[1] - 1]->get_move() == 'D' && contestants[a[2] - 1]->get_move() == 'D')
	{
		contestants[a[0] - 1]->score_update(1);
		contestants[a[1] - 1]->score_update(1);
		contestants[a[2] - 1]->score_update(1);

	}


}

void print_stats(std::vector<Prisoner*> contestants)
{
	std::cout << "prisoner1 chose " << contestants[0]->get_move() << std::endl;
	std::cout << "prisoner2 chose " << contestants[1]->get_move() << std::endl;
	std::cout << "prisoner3 chose " << contestants[2]->get_move() << std::endl;
	std::cout << "Total score: \n" << "prisoner1 = " << contestants[0]->get_score() << std::endl;
	std::cout << "prisoner2 = " << contestants[1]->get_score() << std::endl;
	std::cout << "prisoner3 = " << contestants[2]->get_score() << std::endl;
}
void print_fast(std::vector<Prisoner*> contestants)
{
	std::cout << "prisoner1 chose " << contestants[0]->get_moves() << std::endl;
	std::cout << "prisoner2 chose " << contestants[1]->get_moves() << std::endl;
	std::cout << "prisoner3 chose " << contestants[2]->get_moves() << std::endl;
	std::cout << "Total score: \n" << "prisoner1 = " << contestants[0]->get_score() << std::endl;
	std::cout << "prisoner2 = " << contestants[1]->get_score() << std::endl;
	std::cout << "prisoner3 = " << contestants[2]->get_score() << std::endl;
}
void detailed()
{
	int i = 0, k = 0;
	std::string player_move = "a";
	char choice;
	std::vector<Prisoner*> contestants;
	//std::vector<std::unique_ptr<Prisoner>> contestants;
	std::cout << "Time to start!" << " But first choose your 3 fighters: Prisoner1 1, Prisoner2 2, Prisoner3 3,Prisoner4 4, Prisoner5 5, Prisoner6 6" << std::endl;

	while (k != 3)
	{
		
		scanf("%c", &choice);
		scanf("%c", &choice);
		//if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6')

		while (!isdigit(choice))
		{
			
			std::cout << "You dumb, it was said to press 1, 2,3,4,5,6" << std::endl;
			scanf("%c", &choice);
			scanf("%c", &choice);
			
		}
		if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6')
			contestants.push_back(Prisoner::make_prisoner(int(choice) - '0'));
		std::cout << " choose more 3 fighters: Prisoner1 1, Prisoner2 2, Prisoner3 3,Prisoner4 4, Prisoner5 5,Prisoner6 6 " << std::endl;

		++k;
	}
	char ent;
	contestants[0]->set_turn();
	contestants[1]->set_turn();
	contestants[2]->set_turn();
	while (player_move[0] != 'q')
	{
		std::cout << "press any key if you want to continue else press q" << std::endl;
		std::cin >> player_move;
		if (player_move[0] == 'q')
			break;
		contestants[0]->strat(contestants);
		contestants[1]->strat(contestants);
		contestants[2]->strat(contestants);
		get_score(contestants);
		print_stats(contestants);
		i++;
	}
}

void fast(int n) {
	int k = 0;
	char choice;
	std::vector<Prisoner*> contestants;
	std::cout << "Time to start!" << " But first choose your 3 fighters: Prisoner1 1, Prisoner2 2, Prisoner3 3,Prisoner4 4, Prisoner5 5, Prisoner6 6" << std::endl;

	while (k != 3)
	{

		scanf("%c", &choice);
		scanf("%c", &choice);
		//
		while (!isdigit(choice))
		{

			std::cout << "You dumb, it was said to press 1, 2,3,4,5,6" << std::endl;
			scanf("%c", &choice);
			scanf("%c", &choice);

		}
		if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6')
			contestants.push_back(Prisoner::make_prisoner(int(choice) - '0'));
		std::cout << " choose more 3 fighters: Prisoner1 1, Prisoner2 2, Prisoner3 3,Prisoner4 4, Prisoner5 5,Prisoner6 6 " << std::endl;

		++k;
	}
	for (int i = 0;i < n;i++)
	{
		contestants[0]->strat(contestants);
		contestants[1]->strat(contestants);
		contestants[2]->strat(contestants);
		get_score(contestants);

	}
	print_fast(contestants);
}
bool NextSet(int* a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}
void tournament(int count)
{
	char n,p;
	int m = 3;
	int k = 0;
	char choice;
	std::cout << "enter count of prisoners you want to play" << std::endl;
	scanf("%c", &n);
	scanf("%c", &n);
	std::vector<Prisoner*> contestants;
	while(!isdigit(n))
	{
		scanf("%c", &n);
		std::cout << "enter count of prisoners you want to play" << std::endl;
	}
	while (k != (int(n)-'0'))
	{
		std::cout << " choose more 3 fighters: Prisoner1 1, Prisoner2 2, Prisoner3 3,Prisoner4 4, Prisoner5 5,Prisoner6 6 " << std::endl;

		scanf("%c", &choice);
		scanf("%c", &choice);
		//
		while (!isdigit(choice))
		{

			std::cout << "You dumb, it was said to press 1, 2,3,4,5,6" << std::endl;
			scanf("%c", &choice);
			scanf("%c", &choice);

		}
		if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6')
			contestants.push_back(Prisoner::make_prisoner(int(choice) - '0'));
		
		++k;
	}
	int* a;
	 p = int(n) - '0';
	a = new int[p];
	for (int i = 0; i < p; i++)
		a[i] = i+1;
	contestants[a[0] - 1]->set_turn();
	contestants[a[1] - 1]->set_turn();
	contestants[a[2] - 1]->set_turn();
	for (int i = 0;i < count;++i)
	{
		contestants[a[0]-1]->strat(contestants);
		contestants[a[1]-1]->strat(contestants);
		contestants[a[2]-1]->strat(contestants);

		get_score_tourn(contestants,a);

	}
	print_stats(contestants);
	contestants[a[0] - 1]->clear_mass();
	contestants[a[1] - 1]->clear_mass();
	contestants[a[2] - 1]->clear_mass();
	contestants[a[0] - 1]->reset_turn();
	contestants[a[1] - 1]->reset_turn();
	contestants[a[2] - 1]->reset_turn();
	std::cout << std::endl;
	if (p >= m)
	{

		while (NextSet(a, p, m))
		{
			contestants[a[0] - 1]->set_turn();
			contestants[a[1] - 1]->set_turn();
			contestants[a[2] - 1]->set_turn();
			for (int i = 0;i < count;++i)
			{
				contestants[a[0] - 1]->strat(contestants);
				contestants[a[1] - 1]->strat(contestants);
				contestants[a[2] - 1]->strat(contestants);

				get_score_tourn(contestants,a);

			}
			std::cout << "prisoner" << a[0] << " moves " << contestants[a[0] - 1]->get_moves() << std::endl;
			std::cout << "prisoner" << a[1] << " moves " << contestants[a[1] - 1]->get_moves() << std::endl;
			std::cout << "prisoner" << a[2] << " moves " << contestants[a[2] - 1]->get_moves() << std::endl;
			std::cout << "Total score: \n" << "prisoner" << a[0] << " = " << contestants[a[0] - 1]->get_score() << std::endl;
			std::cout << "prisoner" << a[1] << " = " << contestants[a[1] - 1]->get_score() << std::endl;
			std::cout << "prisoner" << a[2] << " = " << contestants[a[2] - 1]->get_score() << std::endl;
			contestants[a[0] - 1]->clear_mass();
			contestants[a[1] - 1]->clear_mass();
			contestants[a[2] - 1]->clear_mass();
			contestants[a[0] - 1]->reset_turn();
			contestants[a[1] - 1]->reset_turn();
			contestants[a[2] - 1]->reset_turn();
			std::cout << std::endl;
		}
	}
	int i = 0;
	while (i<p)
	{
		std::cout << "contestant" << i+1 << " ";
		std::cout << contestants[i]->get_score() << std::endl;
		i++;
	}
}
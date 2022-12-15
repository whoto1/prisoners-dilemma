#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string>
#include <random>
#include <vector>
class Prisoner {
public:
	std::string decision;
	int score;
	bool turn;
public:
	static Prisoner* make_prisoner(int choice);
	virtual void strat(std::vector<Prisoner*>& pr) = 0;
	virtual void score_update(int num) = 0;
	virtual char get_move() = 0;
	virtual char get_move(int n) = 0;
	virtual int get_score() = 0;
	virtual std::string get_moves() = 0;
	virtual void clear_mass() = 0;
	virtual void set_turn() = 0;
	virtual void reset_turn() = 0;
	virtual bool get_turn() = 0;
};

class Prisoner1 : public Prisoner { // 
public:
	std::string decision;
	int score = 0;
	bool turn = false;

public:
	void score_update(int count) { score += count;}
	void strat(std::vector<Prisoner*>& pr)
	{
		int n = pr.size(), m = decision.size();
		int random;
		if (m == 0) {
			decision.push_back('C');
		}
		else {
			std::random_device rd;  // Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
			std::uniform_real_distribution<> dis(0, n);
			random = dis(gen);
			if (pr[random]->get_turn() == true)
				decision.push_back(pr[random]->get_move(m));
			else
			{
				while (pr[random]->get_turn() == false)
					random = dis(gen);
				decision.push_back(pr[random]->get_move(m));
			}
				

		}
	}
	char get_move(int n) {
		return decision[n - 1];
	}
	char get_move() {
		int n = decision.size();
		return decision[n - 1];
	}
	int get_score() { return score; }
	std::string get_moves() { return decision; }
	void clear_mass() { decision.clear(); }
	void set_turn() {
		turn = true;
	}
	void reset_turn()
	{
		turn = false;
	}
	bool get_turn() {
		return turn;
	}
};

class Prisoner2 : public Prisoner {
public:
	int grudge_count = 0, score = 0;
	std::string decision;
	bool turn = false;
public:
	
	void score_update(int count) { score += count; }
	void strat(std::vector<Prisoner*>& pr)
	{
		int n = pr.size(), m = decision.size(), i = 0;
		if (m == 0)
		{
			decision.push_back('C');
		}
		else {
			while (i < n)
			{
				if (pr[i] == this) { i++; continue; }
				if (pr[i]->get_turn() == true && pr[i]->get_move(m) == 'D' )	break;
				i++;
			}
				
			if (i<n)
				grudge_count = 2;
			
			if (grudge_count != 0)
			{
				decision.push_back('D');
				--grudge_count;
			}
			else
				decision.push_back('C');
		}
	}
	char get_move(int n) {
		return decision[n - 1];
	}
	char get_move() {
		int n = decision.size();
		return decision[n - 1];
	}
	int get_score() { return score; }
	std::string get_moves() { return decision; }
	void clear_mass() { decision.clear(); }
	void set_turn() {
		turn = true;
	}
	void reset_turn()
	{
		turn = false;
	}
	bool get_turn() {
		return turn;
	}
};

class Prisoner3 : public Prisoner {
public:
	int random, score = 0;
	std::string decision;
	bool turn = false;
public:
	void score_update(int count) { score += count;}
	void strat(std::vector<Prisoner*>& pr)
	{
		int n = pr.size(), m = decision.size(), i = 0;
		if (m == 0)
		{
			decision.push_back('C');
		}
		else {
			std::random_device rd;  // Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
			std::uniform_real_distribution<> dis(0, 2.0);
			random = dis(gen);
			if (random < 1)
				decision.push_back('C');
			else
				decision.push_back('D');
		}
	}
	char get_move(int n) {
		return decision[n - 1];
	}
	char get_move() {
		int n = decision.size();
		return decision[n - 1];
	}
	int get_score() { return score; }
	std::string get_moves() { return decision; }
	void clear_mass() { decision.clear(); }
	void set_turn() {
		turn = true;
	}
	void reset_turn()
	{
		turn = false;
	}
	bool get_turn() {
		return turn;
	}
};

class Prisoner4 : public Prisoner {
public:
	int random, score = 0;
	std::string decision;
	bool turn = false;
public:
	void score_update(int count) { score += count; }
	void strat(std::vector<Prisoner*>& pr)
	{
		int n = pr.size(), m = decision.size(), i = 0;
		if (m == 0)
		{
			decision.push_back('D');
		}
		else {
			std::random_device rd;  // Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
			std::uniform_real_distribution<> dis(0, 2.0);
			random = dis(gen);
			if (random < 1)
				decision.push_back('C');
			else
				decision.push_back('D');
		}
	}
	char get_move(int n) {
		return decision[n - 1];
	}
	char get_move() {
		int n = decision.size();
		return decision[n - 1];
	}
	int get_score() { return score; }
	std::string get_moves() { return decision; }
	void clear_mass() { decision.clear(); }
	void set_turn() {
		turn = true;
	}
	void reset_turn()
	{
		turn = false;
	}
	bool get_turn() {
		return turn;
	}
};

class Prisoner5 : public Prisoner { // 
public:
	std::string decision;
	int score = 0;
	bool turn = false;

public:
	void score_update(int count) { score += count; }
	void strat(std::vector<Prisoner*>& pr)
	{
		int n = pr.size(), m = decision.size();
		int c_count = 0, g_count = 0;
		if (m == 0)
		{
			decision.push_back('D');
		}
		else {
			for (int i = 0;i < n;++i)
			{
				for (int j = 0;j < m;++j)
				{
					if (pr[i]->get_move(j+1) == 'C')
						c_count++;
					else
						g_count++;
				}
			}
			if (c_count >= g_count)
				decision.push_back('C');
			else
				decision.push_back('D');
		}
	}
	char get_move(int n) {
		return decision[n - 1];
	}
	char get_move() {
		int n = decision.size();
		return decision[n - 1];
	}
	int get_score() { return score; }
	std::string get_moves() { return decision; }
	void clear_mass() { decision.clear(); }
	void set_turn() {
		turn = true;
	}
	void reset_turn()
	{
		turn = false;
	}
	bool get_turn() {
		return turn;
	}
};

class Prisoner6 : public Prisoner {
public:
	std::string decision;
	int score = 0;
	bool turn = false;

public:
	void score_update(int count) { score += count; }
	void strat(std::vector<Prisoner*>& pr)
	{
		int n = pr.size(), m = decision.size();
		int c_count = 0, g_count = 0, i = 0;
		if (m == 0)
		{
			decision.push_back('D');
		}
		else {
			while (i < n)
			{
				if (pr[i] == this) { i++; continue; }
				if (pr[i]->get_turn() == true)
				{
					if (pr[i]->get_move(m) == 'C') c_count++;
					else g_count++;
				}
				i++;
			}
			if (c_count == 0)
				decision.push_back('C');
			else if (g_count == 0)
				decision.push_back('C');
			else
			{
				int random;
				std::random_device rd;  // Will be used to obtain a seed for the random number engine
				std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
				std::uniform_real_distribution<> dis(0, 2);
				random = dis(gen);
				if (random == 0)
					decision.push_back('C');
				else
					decision.push_back('D');
			}

		}
	}
	char get_move(int n) {
		return decision[n - 1];
	}
	char get_move() {
		int n = decision.size();
		return decision[n - 1];
	}
	int get_score() { return score; }
	std::string get_moves() { return decision; }
	void clear_mass() { decision.clear(); }
	void set_turn() {
		turn = true;
	}
	void reset_turn()
	{
		turn = false;
	}
	bool get_turn() {
		return turn;
	}
};

Prisoner* Prisoner::make_prisoner(int choice)
{
	if (choice == 1)
		return new Prisoner1;
	else if (choice == 2)
		return new Prisoner2;
	else if (choice == 3)
		return new Prisoner3;
	else if (choice == 4)
		return new Prisoner4;
	else if (choice == 5)
		return new Prisoner5;
	else if (choice == 6)
		return new Prisoner6;
}
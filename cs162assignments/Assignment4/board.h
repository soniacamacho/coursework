#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "bee.h"
#include "ant.h"
#include "bee.h"
using namespace std;

class Board{
private:
	//Insect* bee = new Bee[11];
	vector <Bee > bugs[11] ;
	Ant *ants[11];
	int bank;
	int turn;
public:
	Board();
	void welcome();
	void print_ant_key();
	//void print_board();
	
	void game_ov();
	void print();
 bool get_game_over();
	void getting_ant();
	int get_int(string p);
	bool is_int(string n);
	bool check_h_cost();
	bool tcost();
	bool fcost();
	bool threecost();
	bool sixcost();
	void badmessa();
	void messa(int acost);
	int get_turn()const;
	void set_turn(int t);
	
	 int get_int_two(string p);
	bool is_int_two(string n);
	int get_ant_coord();
	void generate_bee();
	void set_new_h_ant(int cord);
	void set_new_t_ant(int cord);
	void set_new_f_ant(int cord);
	void set_new_lt_ant(int cord);
	void set_new_st_ant(int cord);
	void set_new_w_ant(int cord);
	void set_new_n_ant(int cord);
	void bees_move();
	void ants_attack();
	void del_bee();
	~ Board();
};
#endif                                                                                                                                            
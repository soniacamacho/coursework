#ifndef PLAYERHEADERS_H
#define PLAYERHEADERS_H
//#include "propertyheaders.h"
#include "househeaders.h"
#include "apheaders.h"
#include "businessheaders.h"

using namespace std;

class Player{
    private:
        
        int num_house;
        int numapart;
        int num_b;
        int money;
        int turn;
        int tax;
        int rents;
        //Property *p;
        House *houses;
        Busi * business;
        Apart* apartments;


        House *house_op;
        Busi * business_op;
        Apart* apartments_op;
    public:
        Player();//default constructor
        //Player(int,int,int,int,int,House*,Apart*,Busi*);//non default constructor
        //accessors
        int get_money()const;
        int get_turn()const;
        int get_num_houses()const;
        int get_numb()const;
        int get_numapart()const;
        House get_house(int i)const;
        Busi get_business(int i )const;
        Apart get_apart(int i)const;
        //mutators
        void set_num_houses(int num);
        void set_numb(int nb);
        void set_numapart(int numa);
        void set_money(int m);
        void set_turn(int t);
        void set_houses(int num,House* home);
        void set_business(int nb,Busi* b);
        void set_apart(int numa, Apart* a);
        void turn_funcs();
        bool get_game_over();
        House* resize_house(House ho , House *house , int numh);
        Busi* resize_busi(Busi bo , Busi* business , int num_b);
        Apart* resize_ap(Apart ao , Apart* apartments , int numapart);

        bool is_int(string);
        int get_int(string prompt);

        void print_ava(House&,Busi&,Apart&);
        void pay_tax();
        void pay_mortgage();
        void change_rents();
        void print_ops(House&,Busi&,Apart&);
        void rand_ops();
        void buy_prop(int housenumber,int businessnumber,int apartmentnumber);
        void hurricane();
        void tornado();
        void earthquake();
        void wildfire();
        void stock_crash();
        void gentrefication(string str);
        void rand_events();
        void collecting_rents();
        void sell_props();

        Player(const Player&);
        const Player&  operator = (const Player&);
        ~ Player();
};
#endif
                                                             

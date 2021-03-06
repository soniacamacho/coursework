#ifndef ANT_H
#define ANT_H
#include <iostream>
#include <string>
#include "insect.h"
#include "ant.h"
using namespace std;
class Ant : public Insect {
	private:
		int cost;
	public:
		Ant();
		virtual string get_type();
		virtual int get_armor();
		virtual void set_armor(int a);
		int two_dolla();
		int four_dolla();
		int three_dolla();
		int six_dolla();
};

class Harvester : public Ant {	
	public:
		Harvester();
		//turn();
};
class Thrower : public Ant {	
	public:
		Thrower();
		//turn();
};
class Fire : public Ant {	
	public:
		Fire();
		//turn();
};
class Long_Thrower : public Ant {	
	public:
		Long_Thrower();
		//turn();
};
class Short_Thrower : public Ant {	
	public:
		Short_Thrower();
		//turn();
};
class Wall : public Ant {	
	public:
		Wall();
		//turn();
};
class Ninja : public Ant {	
	public:
		Ninja();
		//turn();
};



#endif    
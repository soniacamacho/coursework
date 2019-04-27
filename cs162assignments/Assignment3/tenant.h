#ifndef TENANT_H
#define TENANT_H

#include <iostream>
#include <string>
using namespace std;

struct Tenant {
	string type;
	int max_budget;
	int agree_score;
};
#endif

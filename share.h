#ifndef SHARE_H
#define SHARE_H

#include<iostream>
#include"stock.h"
using namespace std;

class share
{
	stock* product;
	int quantaty;


public:
	share* next;
	share();
	share(stock *,int);

	void set_quantaty(int);
	int get_quantaty();
	stock get_product();


};
#endif

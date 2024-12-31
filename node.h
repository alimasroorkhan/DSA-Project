#ifndef NODE_H
#define NODE_H

#include<iostream>
#include"stock.h"
using namespace std;

class node
{
public:
	stock * data;
	node *next;

	node();
	node(stock *a);
	


};

#endif


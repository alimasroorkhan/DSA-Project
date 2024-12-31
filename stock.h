#ifndef STOCK_H // Start of include guard
#define STOCK_H

#include<iostream>
#include<string>
#include<cmath>
#include<random>
using namespace std;

class stock
{
	double price,preprice;
	double percentage;
	string name;


public:

	stock();
	stock(string,int);
	void set_new_price();
	double get_price();
	void set_percentage();
	double get_percentage();
	string get_name();
	

};

#endif // End of include guard
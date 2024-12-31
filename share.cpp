#include "share.h"

share::share()
{
	product = NULL;
	quantaty = 0;
}

share::share(stock *a,int b)
{
	product = a;
	quantaty = b;
}

int share::get_quantaty()
{
	return quantaty;
}

stock share::get_product()
{
	return *product;
}

void share::set_quantaty(int a)
{
	quantaty = a;
}
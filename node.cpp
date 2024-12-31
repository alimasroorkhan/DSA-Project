#include "node.h"

node::node()
{
	data = NULL;
	next = NULL;

}

node::node(stock * a)
{
	data = a;
	next = NULL;



}
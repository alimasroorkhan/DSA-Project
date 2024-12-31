#include "link_list_shares.h"


link_list_shares::link_list_shares()
{
	head = NULL;
}
void link_list_shares::insert(share*a)
{

	if (head == NULL)
	{
		head = a;
	}
	else
	{
		share* b = head;
		while (b->next!=NULL)
		{
			b = b->next;

		}
		b->next = a;
	}

}

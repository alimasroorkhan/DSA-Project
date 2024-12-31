#include<iostream>
#include"share.h"
#include"link_list.h"
#include"link_list_shares.h"
#include<fstream>

using namespace std;

class user
{
	
	string username;
	double balance;
	link_list_shares users_shares;
	string password;

public:
	user();
	user(string);
	void set_balance(double);
	double get_balance();
	string get_username();
	void get_password();
	void buy(link_list *l);
	void display_users_shares();
	void sell();
	void prediction();
	void logout();
	void login(link_list&);



};


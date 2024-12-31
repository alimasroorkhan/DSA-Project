#include"password masking.h"

string password_masking()
{
	char ch;
	string password;

	/*_getch() bascally hides one keybord press
	 bur still stores them on varibales assigned 
	 also rember the_getch() returns a char and not a string
	 */

	while ((ch = _getch())!= '\r')
	{
		if (ch == '\b')
		{
			if (password.length() > 0)
			{
				password = password.substr(0, password.length() - 1);

				cout << "\b \b";


			}


		}
		else
		{

			password += ch;
			cout << "*";





		}

	}
	

	return password;

}
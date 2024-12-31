#include <iostream>
#include <string>
#include <cctype> // For isupper, islower, isdigit
#include <set>    // For checking special characters

using namespace std;

bool password_checker(string password)
{
    int len = password.length();

   
    set<char> special_chars = { '!', '@', '#', '$', '%', '^', '&', '*' };

    int Ucount = 0, Lcount = 0, Numcount = 0, special_count = 0;

 
    for (int i = 0; i < len; i++)
    {
       
        if (isupper(password[i]))
        {
            Ucount++;
        }

      
        if (islower(password[i]))
        {
            Lcount++;
        }

       
        if (isdigit(password[i]))
        {
            Numcount++;
        }

        // Check for special characters
        if (special_chars.find(password[i]) != special_chars.end())
        {
            special_count++;
        }
    }

    // Criteria for a valid password
    if (Ucount > 0 && Lcount > 0 && Numcount > 0 && special_count > 0 && len >= 8)
    {
        return true; // Password is valid
    }
    else
    {
        return false; // Password does not meet the criteria
    }
}

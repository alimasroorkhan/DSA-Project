#include"Login.h"
#include"password masking.h"
#include"password_checker.h"
#include <windows.h>  // Required for Sleep()


string login() {
    fstream file;
    string name, password;

    while (true) {
    cout << "Enter username: ";
    cin >> name;  // Get the username input

    
        file.open(name, ios::in); 

        if (file.is_open()) {
            string fpassword;
            getline(file, fpassword);  

            while (true) {  
                cout << "Enter password: ";
                password = password_masking();  // Mask the password input

                if (password == fpassword) {
                    cout << "\nLogged in successfully!\n";
                    return name;  // Exit the login function if the password is correct
                }
                else {
                    cout << "\rIncorrect password! Please try again.   ";
                    Sleep(2000);  // Wait for 2 seconds

                    // Clear the line after showing the incorrect password message
                    cout << "\r";
                    for (int i = 0; i < 80; i++) {
                        cout << " ";
                    }
                    cout << "\r";
                }
            }
        }
        else {
            cin.ignore();
            cout << "\rUsername not found! Please try again.   ";
            Sleep(2000);  // Wait for 2 seconds

            // Clear the line after showing the username error message
            cout << "\r";
            for (int i = 0; i < 80; i++) {
                cout << " ";
            }
            cout << "\r";
        }

        file.close();  // Close the file after checking the username and password
    }

  
}


string Register()
{
    string username, password;
    fstream new_user;
    bool accepted = false;

    cout << "Enter username: ";
    cin >> username;
 
    // Loop until a valid password is entered
    while (true)
    {
        cout << "Enter password: ";
        password = password_masking();  // Mask password input

        // Check if the password meets the criteria
        if (password_checker(password))
        {
            break;  
        }
        else
        {
            cout << "\rPassword does not meet the criteria. Please try again.   ";
            
            Sleep(2000);
            
            cout << "\r";
            for (int i = 0; i < 80; i++)
            {
                cout << " ";
            }
            cout << "\r";

            
           
           
            
        }
    }

    // Open the file to store the username and password
    new_user.open(username, ios::out);

    if (new_user.is_open())
    {
        new_user << password;  // Write the password to the file
        cout << "\nRegistration successful!" << endl;
    }
    else
    {
        cout << "Failed to create user file." << endl;
    }

    new_user.close();  // Close the file

    return username;
}
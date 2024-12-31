#include "Login.h"
#include "stock.h"
#include <iomanip> // For setting precision and width
#include "link_list.h"
#include <Windows.h>
#include <thread>
#include <iostream>
#include "share.h"
#include <limits> // For numeric_limits
#include <vector> // For storing owl art
#include "user.h"
#include <mutex> // For thread safety
using namespace std;

void open_market(stock* s[], int t) {
    fstream file;
    string nam;
    string pri;
    int count = 0;

    // Open the file
    file.open("Market.txt", ios::in);
    if (!file) {
        cout << "Error: File doesn't exist or couldn't be opened.\n";
        return;
    }

    // Read the file line by line
    while (count < t && getline(file, nam) && getline(file, pri)) {
        try {
            double price = stod(pri); // Convert price string to double
            s[count] = new stock(nam, price); // Dynamically allocate stock object
            ++count;
        }
        catch (const invalid_argument& e) {
            cerr << "Error: Invalid price format for stock '" << nam << "'. Skipping.\n";
        }
        catch (const exception& e) {
            cerr << "Error: Unexpected issue. " << e.what() << "\n";
        }
    }

    // Handle cases where fewer stocks are read than expected
    if (count < t) {
        cout << "Warning: Only " << count << " stocks loaded out of " << t << ".\n";
    }

    file.close(); // Close the file
}

void close_market(stock* s[], int t) {
    fstream file;

    // Open the file for writing
    file.open("Market.txt", ios::out);
    if (!file) {
        cout << "Error: Could not open the file for writing.\n";
        return;
    }

    // Write each stock's data to the file
    for (int i = 0; i < t; ++i) {
        if (s[i]) {
            file << s[i]->get_name() << "\n"
                << s[i]->get_price() << "\n";
        }
        else {
            cerr << "Warning: Stock at index " << i << " is null. Skipping.\n";
        }
    }

    file.close(); // Close the file

}

// Function to display the owl art line by line
void display_owl() {
    vector<string> owl = {
        "                ?B!                                                          !B?",
        "                 B@G                                                          G@B",
        "                 7@@J.                                                      .J@@7",
        "                  ~P@&GY?7!!7777!~^:.                        .:^~!7777!!7?YG&@P~",
        "                    :7YPGBBGGGGGBBB##BP?^                ^?PB##BBBGGGGBBBGPY7:",
        "                           ..      .^!JP##?.          .?##PJ!^.      .",
        "                          ~7     ...    .J@B^        ^B@J.    ...    .?^",
        "                         ?P.   755YYYY~   ~@B.      .B@~   !YYYJ557   :G7",
        "                        Y#:  :BP^~??7!5?   P@!      !@P   JB!???~^GB:  ^&?",
        "                       J@!   5& :#^ 7!J5   G@^      ^@G   PY7? ^&: &5   ?@7",
        "                      ~@G    Y@: ?Y??YJ.  J@Y        Y@?  .55??Y? :&Y   .#@^",
        "                      G@7    .5#?:.::. .!G&?    !!    ?#G!. .::.:?#5.    J@5",
        "                     ^@@^      ~YGP55PPGP?.   .Y@@5.   :?PGPP55PGY^      !@&:",
        "                     !@@^         .^^^:.     ~#@@@@#~     .:^^^.         !@@^",
        "                     ^@@?                    ~&@@@@&~                    Y@&:",
        "                      G@#.                    !@@@@!                    ^&@5",
        "                      ^&@G:                    ?@@?                    ^#@B:",
        "                       ^B@#7                    55                   .?@@G:",
        "                        .J&@B?:                                    ^J&@#7",
        "                          .?B@@G?^.                            .~JB@@P!.",
        "                             ^7P#&BPJ!^.                  :~7YG#&B5!:",
        "                                 :~?YPGGP5J7~^:.  .:^~7J5PGGPY7~:",
        "                            ..         .::^~~~^:..:^~~^^:.          .",
        "                           !5.                                      :5~",
        "                         .Y@!                                        7@J",
        "                        :G@P                                          G@P.",
        "                       .B@@^^^           ^?            ?^           ^^!@@G",
        "                       P@@B ^GY!^:....:~JP5P7^:....:^7P5PJ!^:...:^!YG: #@@Y",
        "                      7@@@J  .7PGBBBP55Y7. ~YPBBBBBGPY~ .7PGPGBBBGP?.  5@@@~",
        "                      G@@@!      ..:..        ..::..        .::..      ?@@@P",
        "                     :@@@@~                                            7@@@&.",
        "                     ~@@@@!                                            7@@@&^",
        "                     ~@@@@?   ^7          ??          ??          7^   Y@@@@^",
        "                     :@@@@P   .PG?!~^^~!JG55GJ!~^^~!JG55GJ!^^^~!?GP.   G@@@&.",
        "                      G@@@&:    ~YPGGGGPJ~  ~JPGGGGPJ~  ~JPGGGGPY~    ^@@@@P",
        "                      !@@@@Y                                          5@@@@~",
        "                       P@@@@~                                        !@@@@Y",
        "                       .B@@@#.   .         .          .         .   ^&@@@P",
        "                        .G@@@G.  5!       ^BY.      .YB^       !5  :#@@@P.",
        "                          Y@@@B: ~BGJ??JYPB?5B5JJJJ5B5?BP?777JGB~ ^#@@@J",
        "                           ~B@@&!  ~7YYY?!.  ^7JYYJ7^  .!?JJJ?~  7&@@G^",
        "                             7B@@5.                            :P@@G!",
        "                               ~5&#?.                        .J&#Y^",
        "                                 .~YY~                      !YJ~.",
        "                                     ..!!^?~^?^    ^?^!7:7!..",
        "                                      ^@@P@#G@P    P@B&@5@@^",
        "                                       Y5.G!^B^    ^B:?P 5Y",
        "                                             "
    };

    for (int i = 0; i < owl.size(); i++) {
        cout << owl[i] << endl;
        Sleep(20);
    }
}

// Function to display the owl head (optional)
void display_owl_head() {
    vector<string> owl_head = {
        "                 J@@^                                                          ^@@J                  ",
        "                 ^&@P:                                                        :P@&^                  ",
        "                  ^5@@GJ7~~^~~~~~^^:.                          .:^^~~~~~^~~7JG@@5:                   ",
        "                    :75G#############BPJ~.                .~JPB#############G57:                    ",
        "                         .. ..  ...:^!JP#&P~            ~P&#PJ!^:...  .. ..                          ",
        "                           !~           .~G@5.        .5@G~.           !~                            ",
        "                          5?   .!YYYYY7.   J@P        5@J   .7JYJYY!.   YJ                           ",
        "                        .GP   ^BP~!??7JP^   B@^      ^@B   ~BJ7??!~PB^   GP                          ",
        "                       .G&.  .#P !G^:Y:5J   B@^      ^@B   YP^P:^G7 P#.  ^@P                         ",
        "                       5@7   :@Y ~G7~?YY:  ?@5        5@7  :P5?~7G~ Y@:   J@J                        ",
        "                      ~@#.    ?&Y..^!~^  ^5@5.   ::   .5&5^  ^~!^..Y&?    ^@&:                       ",
        "                      5@P      ^5GPJ???YGBP~    7#&7    ~PBGY???JPB5^      B@J                       ",
        "                      B@5        .^!???7^.    :P@@@@P:    .^7???!^.        G@P                       ",
        "                      B@G                     ?@@@@@@?                    .#@P                       ",
        "                      J@@~                     Y@@@@5                     ?@@7                       ",
        "                      .B@#^                     G@@G                     ~&@G                        ",
        "                       :B@&!                    .##.                    ?@@G.                        ",
        "                        .Y@@G!                   ^^                  .7B@&?                          ",
        "                          ^5&@#Y~.                                .!5&@#J:                           ",
        "                            .7P#@#P?~:                       .:!JG&@#Y~.                             ",
        "                               .^7YPB#BPY7~^..        ..^!?YPB#BGY!:                                 ",
        "                                    .:^!7JJJJ?7~^..^~7?JJJ?7~^.                                      ",
    };

    for (int i = 0; i < owl_head.size(); i++) {
        cout << owl_head[i] << endl;
    }
}


// Function to display the owl art in blue using ANSI escape codes
void display_owl_blue() {
    // Set the text color to blue using ANSI escape code
    cout << "\033[34m";  // Blue color

    vector<string> owl_blue = {
        "      ^?Y55J!.  :!^            ~!. ~!.                  ~!!!!!!!!!!.:~:       ^^ :!!!!!!!!!!:     ",
        "    !B@@&##@@#Y.5@@7         .5@@!~@@Y                  G@@@&&&&&@&:P@&Y:  .7B@&:?@@@&&&&&&@7     ",
        "   ?@@G~.  :J@@G:B@@7  ~YJ: .G@@J !@@5                  G@@J^~~~^:: .?#@@Y?#@@5^ ?@@G^~~~^::.     ",
        "   B@@^      G@@~.B@@!!@@@G^G@@?  !@@5                  G@@@&&&@#^    .7#@@@Y:   ?@@@&&&&&7       ",
        "   J@@5:   .7&@B. :#@&&@@@@&@@7   !@@5                  G@@57777!.      !@@P     ?@@B77777:       ",
        "    ?#@@BGG&@@P:   :#@@#^G@@&!    !@@&BBBBBBP           G@@#BBBBBB#J    !@@P     J@@&BBBBBB#P     ",
        "     .!JPPPY7:      :YY: :JY^     ^555555555J           ?55555555557    ^557     ~5555555555J  "
    };

    // Print the owl art line by line
    for (int i = 0; i < owl_blue.size(); i++) {
        cout << owl_blue[i] << endl;
    }

    // Reset the text color back to normal (white)
    cout << "\033[0m";  // Reset color
}

// Create some stock objects
stock* s1[3];


// Mutex for thread safety
mutex mtx;

// Function to continuously update and display stock market values
void stock_market(link_list& l) {
    while (true) {
        // Lock the mutex for thread-safe access
        mtx.lock();
        l.updata_values();
        

        close_market(s1,3);
      
        mtx.unlock();

        // Pause for 10 seconds
        Sleep(10000); 
    }
}




int main() {
    string username;  // Store the username
    bool validChoice = false;

    // Display owl art
    display_owl();

    Sleep(3000); // Pause for 3 seconds

    // Login/Register loop
    while (!validChoice) {
        system("cls"); // Clear the screen

        display_owl_head(); // Display owl head
        display_owl_blue(); // Display blue owl

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "Enter your choice: ";
        int choice;

        // Input validation
        if (cin >> choice) { // If input is valid
            switch (choice) {
            case 1:
                username = Register();  // Assuming Register() is defined elsewhere
                validChoice = true;
                break;

            case 2:
                username = login();  // Assuming login() is defined elsewhere
                validChoice = true;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                Sleep(2000); // Wait for 2 seconds before restarting
                break;
            }
        }
        else {
            // If input is invalid (e.g., non-integer)
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // Clear the error state
            cin.ignore(); // Ignore invalid input
            Sleep(2000); // Wait for 2 seconds before restarting
        }
    }

    system("cls"); // Clear the screen after successful login/register

    // Create and initialize the linked list
    link_list l;


    //enter values in the stock
    open_market(s1, 3);

    // Create nodes for each stock
    node* n1 = new node(s1[0]);
    node* n2 = new node(s1[1]);
    node* n3 = new node(s1[2]);z

    // Insert nodes into the linked list
    l.insertion(n1);
    l.insertion(n2);
    l.insertion(n3);

    // Launch the stock market update in a separate thread

    thread stockThread(stock_market, ref(l));

    // Detach the thread to let it run independently
    stockThread.detach();

    // User functionality
    user a(username);

    // Login for the user
    a.login(l);

    Sleep(3000);

    while (true) {  // Loop to allow repeated actions
        system("cls");

        int choices;

        cout << "Please select our services\n";
        cout << "1. Check the stock market\n";
        cout << "2. Check your balance\n";
        cout << "3. Buy stocks\n";
        cout << "4. Add balance\n";
        cout << "5. Check your investment\n";
        cout << "6. Sell stocks\n";
        cout << "7. Logout\n";
        cout << "Enter your choice: ";

        if (cin >> choices) {  // Validate input for user choices
            switch (choices) {
            case 1:
                while (true) {
                    system("cls");      // Clear the screen before displaying new data
                    l.display();        // Display updated stock market details
                    cout << "To exit, press any key...";

                    // Check if any key is pressed to exit
                    if (_kbhit()) {
                        _getch();   // Read and discard the pressed key
                        break;      // Exit the loop
                    }

                    Sleep(10000);        // Pause for 10 seconds before updating again
                }
                break;
            case 2:
                system("cls");      // Clear the screen before displaying new data
                cout << "Your balance is: $" << a.get_balance() << endl;
                cout << "To exit, press any key...";
                while (true) {
                    // Check if any key is pressed to exit
                    if (_kbhit()) {
                        _getch();   // Read and discard the pressed key
                        break;      // Exit the loop
                    }
                }
                break;
            case 3:
                system("cls");      // Clear the screen before displaying new data
                a.buy(&l);
                Sleep(3000);
                break;
            case 4:
                system("cls");      // Clear the screen before displaying new data
                cout << "Enter amount to add to balance: ";
                double amount;
                cin >> amount;
                a.set_balance(amount); // Assuming add_balance is implemented to update the balance
                cout << "Balance was added successfully.";
                Sleep(2000);
                break;
            case 5:
                while (true) {
                    system("cls"); // Clear the screen before displaying new data
                    a.display_users_shares(); // Display the user's shares
                    cout << "To exit, press any key..." << endl;

                    // Check if any key is pressed to exit
                    if (_kbhit()) {
                        _getch(); // Read and discard the pressed key
                        break; // Exit the loop
                    }

                    Sleep(5000); // Pause for 5 seconds before updating again
                }
                break;
            case 6:
                system("cls");      // Clear the screen before displaying new data
                a.sell();
                Sleep(3000);
                break;

            case 7:
                a.logout(); // Logout function should be called here
                close_market(s1,3); //close the market and save the values in the file

                // Exit the program after logout
                cout << "You have logged out successfully.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                Sleep(2000);
                break;
            }
        }
        else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore();
            Sleep(2000);
        }
    }

    // Clean up dynamically allocated memory
    delete s1;
 

    return 0;
}
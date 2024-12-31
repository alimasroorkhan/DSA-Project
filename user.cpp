#include "user.h"
#include <iomanip>
#include "link_list_shares.h"


user::user(string n)
{
    username = n;
    cout << "Welcome " << n << "!" << endl;
    balance = 0;
}

void user::set_balance(double a)
{
    balance += a;
    cout << "Your balance is $: " << balance << endl;
}

double user::get_balance()
{
    return balance;
}

void user::get_password() {
    fstream file;
    string password;  // Declare a local string variable to store the password

    // Open the file in read mode
    file.open(username, ios::in);
    if (!file) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    // Assuming the password is stored in the first line
    if (getline(file, password)) {
        this->password = password;  // Set the class member variable
    }
    else {
        cout << "Error: Unable to read password from file.\n";
    }

    file.close();
}

void user::buy(link_list* l) {
    bool found = false;
    string n;
    node* current = l->head;

    while (!found) {

        // Display available shares
        cout << "\033[1;36mAvailable shares:\033[0m\n"; // Cyan color
        cout << "\033[1;33m" << left << setw(20) << "Name" << setw(20) << "Current Price" << "\033[0m" << endl; // Yellow color

        node* display = l->head; // Reset display pointer
        while (display != nullptr) {
            cout << left << setw(20) << display->data->get_name() << setw(20) << display->data->get_price() << endl;
            display = display->next;
        }

        cout << "\nPlease enter the stock you want to buy: ";
        cin >> n;

        // Search for the stock
        current = l->head; // Reset current pointer
        while (current != nullptr) {
            if (current->data->get_name() == n) {
                found = true;
                break; // Stock found
            }
            current = current->next;
        }

        if (!found) {
            cout << "Error: Stock doesn't exist. Please try again.\n";
        }
    }

    int b;
    double total_cost;

    // Enter quantity and process purchase
    cout << "Enter the number of shares you want to buy: ";
    cin >> b;

    if (b <= 0) {
        cout << "Error: Number of shares must be positive. Transaction aborted.\n";
        return;
    }

    total_cost = b * current->data->get_price();
    if (total_cost > balance) {
        cout << "Error: Insufficient balance! Transaction aborted.\n";
    }
    else {
        balance -= total_cost;
        share* new_share = new share(current->data, b); // Create the new share object
        users_shares.insert(new_share);                // Insert into user's shares list
        cout << "Purchase successful! You bought " << b << " shares of " << n << ".\n";
    }
}

void user::display_users_shares() {
    if (users_shares.head == nullptr) {
        cout << "You have no shares." << endl;
        return;
    }

    cout << left << setw(20) << "Stock Name"
        << setw(10) << "Price"
        << setw(20) << "Shares Owned"
        << setw(20) << "Percentage Change" << endl;

    share* current = users_shares.head;
    while (current != nullptr) {
        // Output the stock name, price, and shares owned
        cout << left << setw(20) << current->get_product().get_name()
            << fixed << setprecision(2) // Ensure two decimal places for the price
            << setw(10) << current->get_product().get_price()
            << setw(20) << (current->get_product().get_price() * current->get_quantaty());

        // Color the percentage based on its value
        double percentage = current->get_product().get_percentage(); // Use getter here
        if (percentage < 0) {
            cout << "\033[31m"; // Red color for negative percentages
        }
        else {
            cout << "\033[32m"; // Green color for positive percentages
        }

        // Print the percentage and reset color
        cout << setw(20) << percentage << "%" << "\033[0m" << endl;

        current = current->next;
    }
}

void user::sell() {
    while (true) {
        // Display the user's shares
        cout << "\033[1;36mYour shares are:\033[0m\n"; // Cyan color
        cout << "\033[1;33m" << left << setw(20) << "Name" << setw(20) << "Shares" << "\033[0m" << endl; // Yellow color


        share* current = users_shares.head;
        while (current != nullptr) {
            cout << left << setw(20) << current->get_product().get_name()
                << setw(20) << current->get_quantaty() << endl;
            current = current->next;
        }

        // Input for the stock name and quantity to sell
        string stockName;
        int sellQuantity;

        cout << "\nEnter the share you want to sell: ";
        cin >> stockName;

        cout << "Enter the number of shares you want to sell: ";
        cin >> sellQuantity;

        // Validate input
        bool isFound = false;
        current = users_shares.head;
        share* previous = nullptr;

        while (current != nullptr) {
            if (current->get_product().get_name() == stockName) {
                isFound = true;

                // Check if the user owns enough shares
                if (current->get_quantaty() < sellQuantity) {
                    cout << "Error: You do not have enough shares of " << stockName
                        << " to sell. Try again.\n" << endl;
                    isFound = false; // Force re-entry of valid data
                }
                break;
            }
            previous = current;
            current = current->next;
        }

        if (!isFound) {
            cout << "Error: You do not own shares of " << stockName
                << ". Please enter a valid share name.\n" << endl;
            continue; // Loop back to re-enter valid values
        }

        // Calculate profit from the sale
        int profit = current->get_product().get_price() * sellQuantity;

        // Deduct the sold shares
        current->set_quantaty(current->get_quantaty() - sellQuantity);
        cout << sellQuantity << " shares of " << stockName << " sold successfully!" << endl;

        // Remove the share node if all shares are sold
        if (current->get_quantaty() == 0) {
            if (previous == nullptr) {
                // If the node to delete is the head
                users_shares.head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current; // Free the memory
            cout << "You have sold all your shares of " << stockName << "." << endl;
        }

        // Update the user's balance with the profit
        balance += profit;
        cout << "Profit from the sale: " << profit << endl;
        cout << "Updated balance: " << balance << endl;

        break; // Exit the loop after a successful sale
    }
}

void user::logout() {
    fstream file;
    share* current = users_shares.head;

    // Open the file in write mode to overwrite the user's data
    file.open(username, ios::out);
    if (!file) {
        cout << "Error: Unable to open file for logout.\n";
        return;
    }
    //saves the users password
    file << password << endl;
    // Save the balance and owned shares to the file
    file << balance << endl; // First line is the balance

    while (current != nullptr) {
        file << current->get_product().get_name() << endl;  // Save share name
        file << current->get_quantaty() << endl;           // Save share quantity
        current = current->next;
    }

    file.close();
    cout << "Logout successful! Data saved.\n";
}

void user::login(link_list& a) {
    fstream file;
    string val;
    node* current = a.head;

    // Open the file in read mode
    file.open(username, ios::in);
    if (!file) {
        cout << "Error: Unable to open file for login.\n";
        return;
    }

    // Read the first line for password (assuming it is stored as a string)
    getline(file, val);
    password = val;  // Store password as string, no need to convert to double

    // Read the balance from the second line
    getline(file, val);
    try {
        balance = stod(val);  // Convert string to double for balance
    }
    catch (const std::invalid_argument& e) {
        cout << "Error: Invalid balance format.\n";
        file.close();
        return;
    }
    catch (const std::out_of_range& e) {
        cout << "Error: Balance value out of range.\n";
        file.close();
        return;
    }

    // Read and process the remaining lines for shares
    while (getline(file, val)) {
        bool found = false;
        current = a.head;

        // Find the matching stock in the list
        while (current != nullptr) {
            if (val == current->data->get_name()) {
                found = true;
                share* newShare = new share(current->data, 0); // Create a new share object
                getline(file, val); // Read the quantity
                try {
                    newShare->set_quantaty(stoi(val));  // Set the quantity of shares
                }
                catch (const std::invalid_argument& e) {
                    cout << "Error: Invalid quantity format for stock: " << val << ".\n";
                    delete newShare; // Clean up the created share object
                    continue;
                }

                users_shares.insert(newShare); // Insert it into the user's shares list
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Error: Stock not found in the list: " << val << ".\n";
        }
    }

    file.close();
}




#include "link_list.h"
#include <iostream>
#include <iomanip>
using namespace std;

link_list::link_list() {
    head = nullptr;
}

void link_list::insertion(node* a) {
    if (head == nullptr) {
        head = a;
    }
    else {
        node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = a;
    }
}

void link_list::display() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << left << setw(20) << "Name"
        << setw(10) << "Price"
        << setw(20) << "Percentage Change" << endl;

    node* current = head;
    while (current != nullptr) {
        // Output the name and price
        cout << left << setw(20) << current->data->get_name()

            << fixed << setprecision(2)  // Ensures two decimal places

            << setw(10) << current->data->get_price();

        // Color the percentage based on its value
        double percentage = current->data->get_percentage();
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

void link_list::updata_values() {
    node* current = head;
    while (current != nullptr) {
        current->data->set_new_price();
        current = current->next;
    }
}

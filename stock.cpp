#include "stock.h"

stock::stock() {
    name = "Unnamed";
    price = -1;
    percentage = 0.0;
    preprice = -1;  // Start preprice as -1 to avoid calculation issues
}

stock::stock(string a, int b) {
    name = a;
    price = b;
    percentage = 0.0;
    preprice = b;  // Set preprice to initial price
}

void stock::set_new_price() {
    random_device rd;                          // Seed for the random number generator
    mt19937 gen(rd());                         // Mersenne Twister engine
    normal_distribution<double> dist(0.0, 0.5); // Normal distribution with small changes in stock price (volatility)

    double currentPrice = price;               // Starting stock price
    double previousPrice = preprice;           // Use preprice for previous value

    double drift = 0.0;                     // Small drift (average daily return, can lead to posiative or negative value)
    double volatility = 0.02;                  // Volatility (standard deviation of returns)

    // Calculate the change in price using the drift and volatility
    double dailyReturn = drift + volatility * dist(gen);

    // Calculate the new stock price based on the previous price and daily return
    currentPrice *= (1 + dailyReturn);

    // Ensure that stock price doesn't go below 0
    if (currentPrice < 0) {
        currentPrice = 0;
    }

    // Update price and previous price
    preprice = price;   // Update preprice before setting the new price
    price = currentPrice;  // Update price with new calculated value

    // Update percentage based on the change
    set_percentage();
}

void stock::set_percentage() {
    // Prevent division by zero by ensuring preprice is not zero
    if (preprice != 0) {
        double numinater = price - preprice;
        percentage = (numinater / preprice) * 100;
    }
}

double stock::get_price() {
    return price;
}

double stock::get_percentage() {
    return percentage;
}

string stock::get_name()
{
    return name;
}

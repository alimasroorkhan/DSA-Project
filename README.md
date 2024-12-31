# Stock Market Application

The Stock Market Application is a course project developed for **CSC 221: Data Structures and Algorithms (DSA)**. Designed as part of a semester assignment, this project demonstrates the application of core data structures and algorithms to build a functional and efficient software solution for stock trading and portfolio management.

This application was developed as a requirement for the DSA course at Bahria University, Islamabad, to apply theoretical concepts to a real-world scenario. The project emphasises efficient data handling, modular design, and user experience, showcasing proficiency in C++ programming and fundamental data structures.

## Key Features
The application includes secure user authentication with account creation, login/logout functionality, password masking, and validation mechanisms for robust security. Users can manage stocks with dynamic updates, including attributes like name, current price, previous price, and percentage change. The system supports buying and selling shares with balance validation, and all stock data is stored persistently in a text file (`market.txt`), enabling session continuity. Users can also track their portfolio in real-time, including detailed insights into owned shares and values, with intuitive console-based navigation simplifying stock viewing, trading, and portfolio management.

## Technical Implementation
The implementation leverages linked lists for dynamic management of stocks and user-owned shares, along with custom classes such as `Stock`, `Share`, `Node`, and `User` for modular encapsulation of logic. Algorithms ensure efficient transaction handling with real-time price computations and validation of user input, portfolio updates, and authentication. Persistent data storage is achieved using `<fstream>`, with dynamic loading of initial stock data from `market.txt`. Error-handling mechanisms include robust validation and debugging to ensure reliability during development.

## Future Enhancements
Future plans for the application include real-time API integration for live stock price updates, advanced analytics tools such as performance charts and market trend analysis, educational resources for trading strategies, and community features to foster collaboration and knowledge sharing.

## Tools and Libraries
This project was developed in **C++** using the following:
- Libraries: `<iostream>`, `<fstream>`, `<string>`, `<conio.h>`
- Development Environment: GCC and compatible C++ IDEs

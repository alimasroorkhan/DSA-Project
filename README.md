Stock Market Application

The Stock Market Application is a course project developed for CSC 221: Data Structures and Algorithms (DSA). Designed as part of a semester assignment, this project demonstrates the application of core data structures and algorithms to build a functional and efficient software solution for stock trading and portfolio management.

Project Context

This application was developed as a requirement for the DSA course at Bahria University, Islamabad, to apply theoretical concepts to a real-world scenario. The project emphasises efficient data handling, modular design, and user experience, showcasing proficiency in C++ programming and fundamental data structures.

Key Features

•	User Authentication:
o	Account creation and secure login/logout with password masking.
o	Validation and error-handling mechanisms for robust security.
•	Stock Management:
o	Dynamic stock updates with attributes like name, current price, previous price, and percentage change.
o	Functionality to buy and sell shares with balance validation.
o	Persistent stock data storage for session continuity.
•	Portfolio Management:
o	Real-time tracking of owned shares, including quantities and value.
o	Detailed portfolio insights for informed investment decisions.
•	Data Persistence:
o	Stock data stored in a text file (market.txt) with dynamic loading and saving.
o	Reliable and seamless session handling through file operations.
•	User Interface:
o	Console-based interface with intuitive navigation for stock viewing, trading, and portfolio management.

Technical Implementation

•	Core Data Structures:
o	Linked Lists: Utilised for dynamic management of stocks and user-owned shares.
o	Custom Classes: Encapsulation of logic in modular classes such as Stock, Share, Node, and User.
•	Algorithms:
o	Efficient transaction handling with real-time price computations.
o	Validation algorithms for user input, portfolio updates, and authentication.
•	Error Handling:
o	Robust error-checking for stock transactions, balance updates, and user interactions.
o	Debugging mechanisms incorporated during development.
•	File Handling:
o	Persistent data storage using <fstream> for reliable data retention across sessions.
o	Dynamic loading of initial stock data from market.txt.

Future Enhancements

•	Real-Time API Integration: Add APIs for live stock price updates.
•	Advanced Analytics: Implement performance charts, market trend analysis, and predictive tools.
•	Educational Features: Provide resources for trading strategies and market insights.
•	Community Features: Foster collaboration with forums or chat for strategy discussions.

Tools and Libraries

•	Language: C++
•	Core Libraries: <iostream>, <fstream>, <string>, <conio.h>
•	Development Environment: GCC and compatible C++ IDEs

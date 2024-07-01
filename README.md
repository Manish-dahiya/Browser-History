
Browser History Management System
A simple implementation of a browser history management system using C++. This project allows users to navigate through visited URLs, manage history, save sessions to a file, and load sessions from a file.

Features
Navigate backward and forward through browser history.
Display the current page and full history.
Save session history to a file (session.txt).
Load session history from a file (session.txt).
Getting Started
To get a local copy up and running, follow these simple steps.

Prerequisites
C++ compiler (supporting C++11 or higher)
Git (optional, for cloning the repository)
Installation
Clone the repository:

bash
Copy code
git clone https://github.com/yourusername/browser-history.git
Alternatively, download the repository as a ZIP file.

Navigate to the project directory:

bash
Copy code
cd browser-history
Compile the code:

Use your preferred C++ compiler to compile the BrowserHistory.cpp file.
bash
Copy code
g++ BrowserHistory.cpp -o BrowserHistory
Usage
Run the executable:

bash
Copy code
./BrowserHistory
Interact with the program:

Follow the prompts in the console to simulate visiting URLs, navigating history, and managing sessions.
Example
cpp
Copy code
#include <iostream>
#include "BrowserHistory.h"

int main() {
    // Initialize browser history with a homepage
    BrowserHistory browser("https://www.homepage.com");

    // Simulate visiting URLs
    browser.visit("https://www.page1.com");
    browser.visit("https://www.page2.com");

    // Navigate through history
    std::cout << browser.back(1) << std::endl;    // Should return "https://www.page1.com"
    std::cout << browser.forward(1) << std::endl; // Should return "https://www.page2.com"

    // Display current page and full history
    browser.displayCurrentPage();
    browser.displayHistory();

    // Save session to file
    browser.saveSession("session.txt");

    // Load session from file
    browser.loadSession("session.txt");
    browser.displayHistory();

    return 0;
}
Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your improvements.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Contact
For questions or feedback, please conect on twiter https://x.com/Manish_dahiya07.

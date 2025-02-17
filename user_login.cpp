#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to display the decorative heading
void displayHeading() {
    cout << "=============================================\n";
    cout << "          TEJAS SOLUTION PVT. LTD.           \n";
    cout << "=============================================\n";
    cout << "       Login and Registration System         \n";
    cout << "=============================================\n";
}

// Function to check if a username already exists
bool isUsernameTaken(const string& username) {
    ifstream file("database.txt");
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(':');
        string storedUsername = line.substr(0, pos);
        if (storedUsername == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "\n--- Registration ---\n";
    cout << "Enter a username: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Username already taken. Please choose another.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    // Save the credentials to the file
    ofstream file("database.txt", ios::app);
    if (file.is_open()) {
        file << username << ":" << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error: Unable to open database.\n";
    }
}

// Function to log in a user
void loginUser() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("database.txt");
    string line;
    bool loggedIn = false;

    while (getline(file, line)) {
        size_t pos = line.find(':');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);

        if (storedUsername == username && storedPassword == password) {
            loggedIn = true;
            break;
        }
    }

    file.close();

    if (loggedIn) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        displayHeading();
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
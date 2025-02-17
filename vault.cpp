#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a Customer
class Customer {
public:
    string name;
    int customerId;

    Customer(string name, int customerId) : name(name), customerId(customerId) {}
};

// Class to represent an Account
class Account {
public:
    int accountNumber;
    double balance;
    Customer* customer;
    vector<string> transactionHistory;

    Account(int accountNumber, Customer* customer) : accountNumber(accountNumber), balance(0), customer(customer) {}

    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposit: +" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            transactionHistory.push_back("Withdrawal: -" + to_string(amount));
        }
    }

    void transfer(Account& recipient, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance for transfer.\n";
        } else {
            balance -= amount;
            recipient.balance += amount;
            transactionHistory.push_back("Transfer to " + to_string(recipient.accountNumber) + ": -" + to_string(amount));
            recipient.transactionHistory.push_back("Transfer from " + to_string(accountNumber) + ": +" + to_string(amount));
        }
    }

    void displayDetails() {
        cout << "\nAccount Number: " << accountNumber << "\n";
        cout << "Customer Name: " << customer->name << "\n";
        cout << "Balance: ₹" << balance << "\n";
        cout << "Transaction History:\n";
        for (const string& transaction : transactionHistory) {
            cout << " - " << transaction << "\n";
        }
    }
};

// Function to display the decorative heading
void displayHeading() {
    cout << "=============================================\n";
    cout << "          RESERVE INDIA BANK                \n";
    cout << "=============================================\n";
    cout << "       Banking Management System           \n";
    cout << "=============================================\n";
}

int main() {
    vector<Customer> customers;
    vector<Account> accounts;
    int customerIdCounter = 1;
    int accountNumberCounter = 1001;

    while (true) {
        displayHeading();
        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. View Account Details\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, name);
                customers.push_back(Customer(name, customerIdCounter++));
                cout << "Customer created successfully. Customer ID: " << customers.back().customerId << "\n";
                break;
            }
            case 2: {
                if (customers.empty()) {
                    cout << "No customers available. Please create a customer first.\n";
                    break;
                }
                cout << "Select customer by ID:\n";
                for (const Customer& customer : customers) {
                    cout << "ID: " << customer.customerId << ", Name: " << customer.name << "\n";
                }
                int selectedId;
                cin >> selectedId;
                Customer* selectedCustomer = nullptr;
                for (Customer& customer : customers) {
                    if (customer.customerId == selectedId) {
                        selectedCustomer = &customer;
                        break;
                    }
                }
                if (selectedCustomer) {
                    accounts.push_back(Account(accountNumberCounter++, selectedCustomer));
                    cout << "Account created successfully. Account Number: " << accounts.back().accountNumber << "\n";
                } else {
                    cout << "Invalid customer ID.\n";
                }
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ₹";
                cin >> amount;
                for (Account& account : accounts) {
                    if (account.accountNumber == accountNumber) {
                        account.deposit(amount);
                        cout << "Deposit successful.\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ₹";
                cin >> amount;
                for (Account& account : accounts) {
                    if (account.accountNumber == accountNumber) {
                        account.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 5: {
                int fromAccount, toAccount;
                double amount;
                cout << "Enter your account number: ";
                cin >> fromAccount;
                cout << "Enter recipient account number: ";
                cin >> toAccount;
                cout << "Enter transfer amount: ₹";
                cin >> amount;
                Account* sender = nullptr;
                Account* recipient = nullptr;
                for (Account& account : accounts) {
                    if (account.accountNumber == fromAccount) sender = &account;
                    if (account.accountNumber == toAccount) recipient = &account;
                }
                if (sender && recipient) {
                    sender->transfer(*recipient, amount);
                    cout << "Transfer successful.\n";
                } else {
                    cout << "Invalid account number(s).\n";
                }
                break;
            }
            case 6: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                for (Account& account : accounts) {
                    if (account.accountNumber == accountNumber) {
                        account.displayDetails();
                        break;
                    }
                }
                break;
            }
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    const int PIN = 1234;
    double balance = 25000;   // FCFA

    // Extra challenge: PIN with three attempts, break when authenticated
    bool authenticated = false;
    for (int attempt = 1; attempt <= 3; attempt++) {
        int entered;
        cout << "Enter PIN (attempt " << attempt << "/3): ";
        cin >> entered;
        if (entered == PIN) {
            authenticated = true;
            break;
        }
        cout << "Wrong PIN.\n";
    }
    if (!authenticated) {
        cout << "Card blocked. Too many failed attempts.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n===== ATM MENU =====\n"
             << "1. Balance\n2. Deposit\n3. Withdraw\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Balance: " << balance << " FCFA\n";
                break;
            case 2: {
                double amount;
                cout << "Deposit amount: ";
                cin >> amount;
                if (amount <= 0) cout << "Amount must be positive.\n";
                else {
                    balance += amount;
                    cout << "Deposited " << amount << " FCFA.\n";
                }
                break;
            }
            case 3: {
                double amount;
                cout << "Withdraw amount: ";
                cin >> amount;
                if (amount <= 0) cout << "Amount must be positive.\n";
                else if (amount > balance) cout << "Insufficient funds.\n";
                else {
                    balance -= amount;
                    cout << "Withdrew " << amount << " FCFA.\n";
                }
                break;
            }
            case 4:
                cout << "Thank you. Final balance: " << balance << " FCFA\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}



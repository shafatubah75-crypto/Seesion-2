 
#include <iostream>
using namespace std;

void classify(double mark) {
    char grade;
    if (mark >= 80)      grade = 'A';
    else if (mark >= 70) grade = 'B';
    else if (mark >= 60) grade = 'C';
    else if (mark >= 50) grade = 'D';
    else                 grade = 'F';

    cout << "Mark: " << mark << "  Grade: " << grade << "  ";
    if (mark >= 50) cout << "PASS\n";
    else            cout << "FAIL\n";
}

// Keeps asking until a valid mark (0-100) is entered
double readMark() {
    double m;
    while (true) {
        cout << "Enter mark (0-100): ";
        cin >> m;
        if (m >= 0 && m <= 100) return m;
        cout << "Invalid mark! Must be between 0 and 100.\n";
    }
}

int main() {
    char again;
    do {
        int choice;
        cout << "\n1. Grade one mark\n2. Grade average of three marks\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            classify(readMark());
        } else if (choice == 2) {
            double sum = 0;
            for (int i = 1; i <= 3; i++) {
                cout << "Mark " << i << " - ";
                sum += readMark();
            }
            double avg = sum / 3;
            cout << "Average = " << avg << endl;
            classify(avg);
        } else {
            cout << "Invalid choice.\n";
        }

        cout << "Continue? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}




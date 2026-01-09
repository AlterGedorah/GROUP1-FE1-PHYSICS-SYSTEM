#include <iostream>
#include <limits>
using namespace std;

void showMenu() {
    cout << "Physics System\n";
    cout << "0 - Exit\n";
    cout << "7 - Energy/Work\n";
    cout << "8 - Power\n";
    cout << "Enter your choice: ";
}

class PhysicsSystem {
public:
    double calculatePower(double force, double velocity) {
        return force * velocity;
    }

    double calculateWork(double force, double distance) {
        return force * distance;
    }
};

int main() {
    PhysicsSystem physicsCalculator;
    int choice;
    double force, velocity, distance;

    while (true) {
        showMenu();

        // Error Handling
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 0:
                cout << "Exiting program.\n";
                return 0;

            case 7:
                cout << "Calculate Energy/Work\n";
                cout << "Enter the force (N): ";
                cin >> force;
                cout << "Enter the distance (m): ";
                cin >> distance;

                cout << "Energy = "
                     << physicsCalculator.calculateWork(force, distance)
                     << " Joules\n";
                break;

            case 8:
                cout << "Calculate Power\n";
                cout << "Enter the force (N): ";
                cin >> force;
                cout << "Enter the velocity (m/s): ";
                cin >> velocity;

                cout << "Power = "
                     << physicsCalculator.calculatePower(force, velocity)
                     << " Watts\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

        cout << endl;
    }
}

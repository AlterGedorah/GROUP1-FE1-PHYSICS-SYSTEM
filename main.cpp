#include <iostream>
#include <limits>
using namespace std;

void showMenu() {
    cout << "Physics System\n";
    cout << "0 - Exit\n";
    cout << "3 - Force\n";
    cout << "4 - Pressure\n";
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
    double calculateForce(double mass, double acceleration) {
        return mass * acceleration;
    }
    double calculatePressure(double force, double area) {
        return force / area;
    }
};

int main() {
    PhysicsSystem physicsCalculator;
    int choice;
    double force, velocity, distance, mass, acceleration, area;

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

            case 3:
                cout << "Calculate Force\n";
                cout << "Enter mass (kg): ";
                cin >> mass;
                cout << "Enter acceleration (m/s^2): ";
                cin >> acceleration;

                cout << "Force =" 
                    << physicsCalculator.calculateForce(mass, acceleration)
                    << " Newtons\n";
                break;

            case 4:
                cout << "Calculate Pressure\n";
                cout << "Enter force (N): ";
                cin >> force;
                cout << "Enter area (m^2): ";
                cin >> area;

                if (force < 0 || area <= 0) {
                    cout << "Error: Force must be non-negative and area must be greater than zero.\n";
                    break;
                } 
                else {
                    cout << "Pressure = "
                     << physicsCalculator.calculatePressure(force, area)
                     << " Pascals\n";
                break;
                     }    

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

#include <iostream>
#include <limits>
using namespace std;

void showMenu() {
    cout << "Physics System\n";
    cout << "0 - Exit\n";
    cout << "1 - Velocity\n";
    cout << "2 - Acceleration\n";
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

    double calculateVelocity(double distance, double time) {
        return distance / time;
    }

    double calculateAcceleration(double velocity, double time, double initialVelocity) {
        return (velocity - initialVelocity) /  time;
    }
};


int main() {
    PhysicsSystem physicsCalculator;
    int choice;
    double force, velocity, distance, time, initialVelocity;

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

            case 1: 
                cout << "Calculate Velocity\n";
                cout << "Enter the Distance (D):";
                cin >> distance;
                cout << "Enter the Time (T):";
                cin >> time;
            if (time == 0 ){
                cout << "Invalid Value";
            } else{cout << "Velocity ="
                    << physicsCalculator.calculateVelocity(distance, time)
                    << "m/s\n";}

                    break;

            
            case 2: 
                cout << "Calculate Acceleration\n";
                cout << "Enter the Velocity (V):";
                cin >> velocity;
                cout << "Enter The Initial Velocity (Vu):";
                cin >> initialVelocity;
                cout << "Enter the Time (T):";
                cin >> time;

                cout << "Acceleration = "
                    << physicsCalculator.calculateAcceleration(velocity, time, initialVelocity)
                    << "m/s²\n";

                break;


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

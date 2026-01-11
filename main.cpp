#include <iostream>
#include <limits>
using namespace std;

class Menu {
    public:
    void showMenu() {
        cout << "Physics System\n";
        cout << "0 - Exit\n";
        cout << "1 - Velocity\n";
        cout << "2 - Acceleration\n";
        cout << "3 - Force\n";
        cout << "4 - Pressure\n";
        cout << "5 - Density\n";
        cout << "6 - Momentum\n";
        cout << "7 - Energy/Work\n";
        cout << "8 - Power\n";
        cout << "9 - Kinetic Energy\n";
        cout << "10 - Resistance\n";
        cout << "Enter your choice: ";
    }
    void showContinue(){
        cout << "Do you want to have another calculation?\n";
        cout << "0 - Exit\n";
        cout << "1 - Continue\n";
    }
};

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
    double calculateForce(double mass, double acceleration) {
        return mass * acceleration;
    }
    double calculatePressure(double force, double area) {
        return force / area;
    }
    double calculateDensity(double mass, double volume) {
        return mass / volume;
    }
    double calculateMomentum(double mass, double velocity) {
        return mass * velocity;
    }
    
    double calculateKineticEnergy(double mass, double velocity) {
        double squaredVelocity = velocity * velocity;
        return 0.5 * mass * squaredVelocity;
    }
    double calculateResistance(double voltage,double electricCurrent){
        return voltage / electricCurrent;
    }

};


int main() {
    PhysicsSystem physicsCalculator;
    Menu menu;
    int choice;

    double force, velocity, distance, mass, acceleration, area,initialVelocity,time, volume,voltage,electricCurrent;

    while (true) {
        menu.showMenu();

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
                if (time == 0) {
                    cout << "Error: Time cannot be zero.\n";
                    break;
                } else{
                    cout << "Velocity ="
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

            case 5:
                cout << "Calculate Density\n";
                cout <<"Enter mass (m): ";
                cin >> mass;
                cout << "Enter volume (V): ";
                cin >> volume;

                if (mass <= 0 || volume <= 0) { 
                     cout << "Error: Invalid input! Mass and volume must be postive or greater than zero.\n";
                    break;
                    }
                else {
                        cout << "Density = "
                        << physicsCalculator.calculateDensity(mass, volume)
                        << "kg per m³\n";
                        break;
                    }
            
            case 6:
                cout << "Calculate Momentum\n";
                cout << "Enter mass (m): ";
                cin >> mass;
                cout << "Enter velocity (m/s): ";
                cin >> velocity;

                if (mass <= 0) {
                    cout << "Error: Invalid input! Mass must be greater than zero.\n";
                    break;
                }
                else {
                    cout << "Momentum = "
                    << physicsCalculator.calculateMomentum(mass, velocity)
                    << "kg·m/s\n";
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
            
            case 9:
                cout << "Calculate Kinetic Energy\n";
                cout << "Enter mass (m): ";
                cin >> mass;
                cout << "Enter the velocity (m/s): ";
                cin >> velocity;
                if (mass < 0) {
                    cout << "Error: Invalid input! Mass must be postive or greater than zero.\n";
                    break;
                } else {
                    cout << "Kinetic Energy = "
                         << physicsCalculator.calculateKineticEnergy(mass, velocity)
                         << " Joules\n";
                }
                break;
            
            case 10:
                cout << "Calculate Resistance\n";
                cout << "Enter voltage (V): ";
                cin >> voltage;
                cout << "Enter the electric current (I): ";
                cin >> electricCurrent;
                if (electricCurrent <= 0 || voltage <=0) {
                     cout << "Error: Invalid input! Current and voltage must be greater than zero!";
                } else {
                    cout << "Resistance = "
                         << physicsCalculator.calculateResistance(voltage,electricCurrent)
                         << " Ohms\n";
                }
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
        menu.showContinue();
        cin >> choice;
        
        if (choice == 0) {
            cout << "Exiting...\n";
            break;  
        } else if (choice == 1) {
            continue; 
        } else {
            cout << "Invalid choice. Returning to menu.\n";
        }
        cout << endl;
    }
}

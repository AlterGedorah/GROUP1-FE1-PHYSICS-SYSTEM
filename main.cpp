#include <iostream>
using namespace std;

void showMenu(){
    cout << "Physics System\n";
    cout << "0 - Exit\n";
    cout << "7 - Energy/Work\n";
    cout << "8 - Power\n";
    cout << "Enter your choice: ";
}
class PhysicsSystem {
    public:
    double measurement;

    double calculatePower(double force, double velocity) {
        return force * velocity;
        cout << "Power = " << calculatePower(force, velocity) << " Watts"<< endl;
    }
    double calculateWork(double force, double distance) {
        return force * distance;
        cout << "Energy = " << calculateWork(force, distance) << " Joules"<< endl;
    }
    
};

int main(){
    PhysicsSystem physicsCalculator;
    int choice;
    double force, velocity, distance;
    
    while (true) {
        showMenu();
        cin >> choice;
        if (choice == 0) {
            break;
        }

        cout << "input Variables:\n";
        

        if (choice == 7){
            cout << "Calculate Energy/Work\n";
            cout << "Enter the force (N): "; 
            cin >> force;
            cout << "Enter the distance (m): ";
            cin >> distance; 
            cout << "Energy = " << physicsCalculator.calculateWork(force, distance) << " Joules"<< endl;
        } else if (choice == 8){
            cout << "Calculate Power\n";
            cout << "Enter the force (N): ";
            cin >> force;
            cout << "Enter the velocity (m/s): ";
            cin >> velocity; 
            cout << "Power = " << physicsCalculator.calculatePower(force, velocity) << " Watts"<< endl;
        }
    }
    return 0;
    
}
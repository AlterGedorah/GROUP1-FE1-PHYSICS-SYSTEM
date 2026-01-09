#include <iostream>
using namespace std;

void showMenu(){
    cout << "Physics System\n";
    cout << "0 - Exit\n";
    cout << "7 - Energy/Work\n";
    cout << "8 - Power\n";
    cout << "Enter choice: ";
}
class PhysicsSystem {
    public:
    double measurement;
   
    
};

int main(){
    int choice;
    double force, velocity, distance;
    while (true) {
        showMenu();
        cin >> choice;
        if (choice == 0) {
            break;
        }
    
    if (choice == 7){
            cout << "Calculate Energy/Work\n";
            cout << "Enter the force (N): ";
            cin >> force;
            cout << "Enter the distance (m): ";
            cin >> distance;
            cout << "Energy = " << force * distance << " Joules"<< endl;


        } else if (choice == 8){
                cout << "Calculate Power\n";
            cout << "Enter the force (N): ";
            cin >> force;
            cout << "Enter the velocity (m/s): ";
            cin >> velocity;
            cout << "Power = " << force * velocity << " Watts"<< endl;

        } else {
            cout << "Invalid Choice!, Please try again\n"; 
        }
    }
    return 0;
}   

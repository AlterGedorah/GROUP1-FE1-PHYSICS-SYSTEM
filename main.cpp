#include <iostream>
using namespace std;

void showMenu(){
    cout << "Physics System";
}
class PhysicsSystem {
    public:
    double measurement;
    
};

int main(){
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
    }
    return 0;
}

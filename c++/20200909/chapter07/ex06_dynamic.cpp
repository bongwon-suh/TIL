#include <iostream>
#include <string>
using namespace std;

class Dog{
public:
    int age;
    string name;

    Dog() {
        cout << "call Dog" << endl;
        age = 1;
        name = "happy";
    }

    ~Dog(){
        cout << "call destructor" << endl;
    }
};

int main(int argc, char const *argv[]) {
    Dog *pDog = new Dog;
    delete pDog;

    return 0;
}
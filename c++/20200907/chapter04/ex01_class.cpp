#include <iostream>
#include <string>
using namespace std;

class Circle{
public:
    int radius;
    string color;

    double calcArea(){
        return 3.14 * radius * radius;
    }
};
int main(int argc, char const *argv[]) {

    Circle obj;
    obj.radius = 100;
    obj.color = "blue";

    cout << obj.calcArea() << endl;
    
    return 0;
}
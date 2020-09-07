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

    Circle pizza1, pizza2; // 객체 생성

    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << pizza1.calcArea() << endl;

    pizza2.radius = 200;
    pizza2.color = "white";
    cout << pizza2.calcArea() << endl;

    
    return 0;
}
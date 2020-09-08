#include <iostream>
using namespace std;

class Circle{
public:
    int x, y;
    int radius;

    Circle(): x(0), y(0), radius(0){}
    Circle(int x, int y, int r): x(x), y(y), radius(r){}

    void print(){
        cout << "radius : " << radius << " @(" <<x << "," << y << ")" << endl;
    }
};

int main(int argc, char const *argv[]) {
    Circle objArray[10];

    for(Circle c: objArray){
        c.print();
    }
    cout << " --------------- " << endl;

    for (Circle& c: objArray){
        c.x = rand()%500;
        c.y = rand()%300;
        c.radius = rand()%100;
    }

    for(Circle c: objArray){
        c.print();
    }

    cout << "----------------" <<endl;
    cout << "Circle memory size : " <<sizeof(Circle) << endl;   //Circle 인스턴스의 크기 12, int 변수 3개 4byte*3
    cout << "array length : " << sizeof(objArray)/sizeof(Circle) << endl; // 배열의 길이

    return 0;
}
#include <iostream>
using namespace std;

class Time{
public:
    int hour;
    int minute;

    //생성자
    Time(int h=0, int m=0){
        hour = h;
        minute = m;
    }
    void print(){
        cout << hour << ":" << minute << endl;
    }
};

int main(int argc, char const *argv[]) {
    Time a;
    Time b(10, 25);

    a.print();
    b.print();

    return 0;
}
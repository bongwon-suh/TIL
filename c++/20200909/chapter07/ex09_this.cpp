#include <iostream>
#include <string>
using namespace std;

class Rectangle{
private:
    int length;
    int width;

public:
    Rectangle(){
        length = 30;
        width = 40;
    }
    ~Rectangle(){}
    void setLength(int length) { this->length = length;}
    int getLength() { return this->length;}
    void setWidth(int width) {this->width = width;}
    int getWidth(){ return this->width;}
};

int main(int argc, char const *argv[]) {
    Rectangle rect;
    cout << "length : " << rect.getLength() << endl;
    cout << "width : " << rect.getWidth() << endl;

    rect.setLength(20);
    rect.setWidth(10);

    cout << "length : " << rect.getLength() << endl;
    cout << "width : " << rect.getWidth() << endl;

    return 0;
}
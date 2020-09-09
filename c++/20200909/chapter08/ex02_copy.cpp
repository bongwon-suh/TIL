#include <string>
#include <iostream>
using namespace std;

class MyArray{
public:
    int size;
    int *data;
    
    MyArray(int size){
        this->size = size;
        data = new int[size];
    }
    ~MyArray(){
        if(data!=NULL){
            delete []data;
        }
    }
};

int main(int argc, char const *argv[]) {
    MyArray buffer(10);
    buffer.data[0]=1;
    {
        MyArray clone = buffer; //복사 생성자 호출
    }   // clone 삭제

    buffer.data[0]=2;
    return 0;
}
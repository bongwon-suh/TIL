#include <iostream>
#include <string.h>
using namespace std;

class MyString{
private:
    char *s;
    int size;

public:
    MyString(char *c){
        size = strlen(c)+1;
        s = new char[size];
        strcpy(s, c);
    }
    ~MyString(){
        delete[]s;
    }
};

int main(int argc, char const *argv[]) {
    MyString str("ABCDEFGHI");
    return 0;
}
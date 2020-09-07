#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string s1, addr;

    cout << "name : ";
    cin >> s1;
    cin.ignore(); //엔터키 제거

    cout << "address : " ;
    getline (cin, addr);

    cout << addr << s1 << "hello" << endl;
    return 0;
}
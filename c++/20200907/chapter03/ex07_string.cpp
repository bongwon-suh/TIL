#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string s = "When in Rome, do as the Romans";

    int size = s.size();
    int index = s.find("Rome");

    cout << size << endl; // heap 영역의 사이즈
    cout << index << endl;
    cout << sizeof(s) << endl;  // stack 영역의 사이즈

    s.insert(0, "Hello !! ");
    cout << s << endl;

    s+=" End of World";
    cout << s << endl;

    s. append("\n--------\n");
    cout << s << endl;

    return 0;
}
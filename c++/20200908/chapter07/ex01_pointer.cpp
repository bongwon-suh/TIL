#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int number = 0;
    int *p = &number;

    cout << p << endl;
    cout << *p << endl;
    
    return 0;
}
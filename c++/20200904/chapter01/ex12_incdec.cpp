#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 100;
    x++;
    cout << x << endl;

    x--;
    cout << x << endl;

    cout << ++x << endl;
    cout << x++ << endl;
    cout << ++x << endl;
    cout << x << endl;
    cout << --x << endl;
    cout << x-- << endl;
    cout << x << endl;

    return 0;
}
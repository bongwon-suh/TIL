#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    bool b;
    int x = 3;
    int y = 3;
    cout << std::boolalpha;

    b = (x == 3) && (y == 3);
    cout << b << endl;

    y = 2;
    b = (x == 3) && (y == 3);
    cout << b << endl;

    return 0;
}
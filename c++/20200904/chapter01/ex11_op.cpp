#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 100;
    int y = 200;

    int result = x + y;

    cout << "x+y:" << result << endl;
    cout << "x-y:" << x - y << endl;
    cout << "x/y:" << x / y << endl;
    cout << "x%3:" << x % 3 << endl;
    cout << 1 / 2 << endl;
    cout << 1 / 2. << endl;

    return 0;
}
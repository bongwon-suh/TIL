#include <iostream>
using namespace std;

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    n = max(2, 3);
    cout << "result : " << n << endl;
    return 0;
}
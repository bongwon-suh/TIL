#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int i = 1;

    cout << "input : ";
    cin >> n;

    while ( i <= 9)
    {
        cout << n << " * " << i << " = " << n*i << endl;
        i++;
    }  

    return 0;
}
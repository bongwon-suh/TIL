#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int x, y;

    cout <<"input x :";
    cin >> x;

    cout << "input y :";
    cin >> y;

    if(x>y){
        cout << "x>y" << endl;
    }
    else if(x < y){
        cout << "x < y" << endl;
    }
    else{
        cout << "x=y" << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
auto add(int x, int y){
    return x+y;
}

int main(int argc, char const *argv[]){
    auto d = 1.0;
    auto sum=add(5,10);

    cout << d << " " << sum << endl;
    return 0;
}
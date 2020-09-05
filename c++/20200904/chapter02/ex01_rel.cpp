#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    bool b;

    b = (1 == 2);

    cout << std::boolalpha; // 부울린을 true false로 출력 ::스코프연산자
    cout << b << endl;

    return 0;
}
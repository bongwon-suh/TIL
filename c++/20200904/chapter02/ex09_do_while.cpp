#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string str;

    do
    {
        cout <<"문자열을 입력하세요";
        getline(cin, str); //cin은 공백을 만나면 데이터 하나로 간주
        // cin >> str;
        cout << "사용자 입력 : " << str << endl;
    } while (str != "종료");
    
    return 0;
}
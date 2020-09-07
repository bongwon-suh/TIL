#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string s = "When in Rome, do as the Romans.";

    for(auto& ch : s){  //char &ch=s[i]
        cout << ch << ' ';
    }
    cout << endl;
    
    for(auto ch : s){  //char &ch=s[i]
        cout << ch << ' ';
    }
    cout << endl;

    for(auto& ch : s){  //char &ch = s[i]
        ch = 'T';
    }
    cout << s << endl;

    for(auto ch : s){  //char
        ch='W';
    }
    cout << s << endl;

    
    return 0;


}
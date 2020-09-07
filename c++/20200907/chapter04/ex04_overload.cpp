#include <iostream>
#include <string>
using namespace std;

class PrintData{
public:
    void print(int i){
        cout << i << endl;
    }
    void print(double f){
        cout << f << endl;
    }
    void print(string s = "No data!"){
        cout << s << endl;
    }
};

int main(int argc, char const *argv[]) {
    PrintData prn;

    prn.print(1);
    prn.print(3.14);
    prn.print("c++ is cool.");
    prn.print();
    
    return 0;
}
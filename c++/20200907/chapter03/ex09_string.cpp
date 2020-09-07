#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    string list[] = {"Hong", "Go", "Du"};

    for(auto& name:list){
        cout << name << endl;
    }
    return 0;
}
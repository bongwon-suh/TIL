#include <iostream>
using namespace std;

class Pizza {
public:
    int size;
    Pizza(int s) : size(s){}
};

Pizza makePizza(){
    Pizza p(10);
    return p;
}

int main(int argc, char const *argv[]) {
    Pizza pizza = makePizza();

    cout << pizza.size << endl;
    
    return 0;
}
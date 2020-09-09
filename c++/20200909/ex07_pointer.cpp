#include <iostream>
#include <string>
using namespace std;
class Dog
{
public:
    int age;
    string name;
    Dog()
    {
        age = 1;
        name = "happy";
    }
    ~Dog() {}
    int getAge() { return age; }
    void setAge(int a) { age = a; }
};
int main()
{
    Dog *pDog = new Dog;
    cout << "age : " << pDog->getAge() << endl;
    pDog->setAge(3);
    cout << "age : " << pDog->getAge() << endl;
    delete pDog;
    return 0;
}
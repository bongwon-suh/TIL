#include <iostream>
#include <string>
using namespace std;
class Dog
{
private:
    int *pAge;
    int *pWeight;

public:
    Dog()
    {
        pAge = new int{1};
        pWeight = new int{10};
    }
    ~Dog()
    {
        delete pAge;
        delete pWeight;
    }
    int getAge() { return *pAge; }
    void setAge(int a) { *pAge = a; }
    int getWeight() { return *pWeight; }
    void setWeight(int w) { *pWeight = w; }
};

int main()
{
    Dog *pDog = new Dog;
    cout << "dog age: " << pDog->getAge() << endl;
    pDog->setAge(3);
    cout << "dog age: " << pDog->getAge() << endl;
    delete pDog;
    return 0;
}
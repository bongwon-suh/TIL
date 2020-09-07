#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int list2[10];

    //배열의 크기 계산 방법
    int length = sizeof(list) / sizeof(int); // 40 / 4 => 10
    // list의 메모리의 크기: int 크기(4) * 10개 --> 40byte

    //복사 전 list2 출력
    for (auto &i : list2)
    {
        cout << i << " ";
    }
    cout << endl;

    // list의 값을 list2로 복사
    for (int i = 0; i < length; i++)
    {
        list2[i] = list[i];
    }

    //복사된 list2 출력
    for (auto &i : list2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << list << endl;

    return 0;
}
#include "Car.hpp" // 검색순서 : cwd(& include dir) -> 사용자 lib -> 컴파일러 lib
#include <iostream> // 검색순서 : 사용자 lib -> 컴파일러 lib
//클래스 정의 파일

void Car::setSpeed(int s){ // ::scopre연산자
    speed = s;
}

int Car::getSpeed(){
    return speed;
}
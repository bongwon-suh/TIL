#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>

class MiniCom{
protected:
    LiquidCrystal_I2C lcd;
    SimpleTimer timer;
public:
    MiniCom();  //생성자
    void init();    //초기화코드
    int setInterval(unsigned long d, timer_callback f);   //타이머 콜백 등록
    void run(); //타이머 운영 및 기타 처리

    //LCD 출력지원 helper함수
    void print(int col, int row, const char *pMsg);
    void print(int row, const char *pMsg);
    void print(int row, const char *pTitle, int value);
    void print(int row, const char *pTitle, int value, const char *pTitle2, int value2);
    void print(int row, const char *pTitle, double value, int width=6);

};
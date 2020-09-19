#include "MiniCom.h"

MiniCom::MiniCom() : lcd(0x27, 16, 2){

}  //생성자

void MiniCom::init(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}    //초기화코드

int MiniCom::setInterval(unsigned long d, timer_callback f){
    return timer.setInterval(d, f);
}   //타이머 콜백 등록

void MiniCom::run(){
    timer.run();
} //타이머 운영 및 기타 처리

void MiniCom::print(int col, int row, const char *pMsg){
    lcd.setCursor(col, row);
    char buf[17];
    sprintf(buf, "%-16s", pMsg);  // 이전의 긴 문장을 덮어쓰기 위해 -16s
    lcd.print(buf);
}

void MiniCom::print(int row, const char *pMsg){
    print(0, row, pMsg);
}

void MiniCom::print(int row, const char *pTitle, int value){
    char buf[17];
    sprintf(buf, "%s: %d", pTitle, value);
    print(0, row, buf);
}

void MiniCom::print(int row, const char *pTitle, int value, const char *pTitle2, int value2){
    char buf[17];
    sprintf(buf, "%s:%d %s:%d", pTitle, value, pTitle2, value2);
    print(0, row, buf);
}



void MiniCom::print(int row, const char *pTitle, double value, int width){
    char buf[17];
    char temp[4];
    dtostrf(value, width, 2, temp);
    sprintf(buf, "%s: %s", pTitle, temp);
    print(0, row, buf);
}

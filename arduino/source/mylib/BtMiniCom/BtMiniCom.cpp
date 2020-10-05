#include "BtMiniCom.h"

BtMiniCom::BtMiniCom(int rx, int tx, btminicom_callback_t callback)
    : MiniCom(), btSerial(rx, tx), callback(callback){

}

void BtMiniCom::init(){
    MiniCom::init();
    btSerial.begin(9600);
}

String BtMiniCom::readLine(){
    String message="";
    while (btSerial.available()){
        char data = (char)btSerial.read();
        if(data=='\r') continue;
        if(data=='\n') break;

        message+=data;
        delay(5);
    }
    return message;
}  // \n\r을 제외한 문자열 리턴

void BtMiniCom::send(const char *msg){
    btSerial.println(msg);
}

void BtMiniCom::run(){
    String msg = readLine();
    if(msg != "" && callback !=NULL ){
        callback(msg);
    }
    MiniCom::run();
}
#include "BtMiniCom.h"
#include <Led.h>

void received(String msg);

BtMiniCom com(2, 3, received);
Led led(13);

void received(String msg){
    if(msg=="on"){
        led.on();
        com.send("OK");
    }
    else if(msg=="off"){
        led.off();
        com.send("ok");
    }
    else{
        com.send("BAD COMMAND");
    }
}


void setup(){
    com.init();
}
void loop(){
    com.run();
}
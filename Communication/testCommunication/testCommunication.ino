#include <SPI.h>
#include <RH_NRF24.h>
#include <communication.h>

uint8_t msg[] = {1, 2, 3, 4};
uint8_t len = sizeof(msg);

bool ok;

Communication com(8, 10);

void setup() {
  Serial.begin(9600);
  ok = com.initRadio();
  if(!ok)
    Serial.println("Init error");
}

void loop() {
  ok = com.sendMsg(msg, len, 1);
  if(!ok)
    Serial.println("Sending error");
  ok = com.receiveMsg(msg, len, 1);
  if(!ok)
    Serial.println("Receiving error");
  else
    Serial.println(msg[0]);
}

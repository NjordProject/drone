#include "../communication.h"

uint8_t msg[] = {1, 2, 3, 4};
uint8_t len = sizeof(msg);

bool ok;

void init() {
  Serial.begin(9600);
  ok = initRadio();
  if(!ok)
    Serial.println("Init error");
}

void loop() {
  ok = sendMsg(msg, len, 1);
  if(!ok)
    Serial.println("Sending error");
  ok = receiveMsg(msg, len, 1);
  if(!ok)
    Serial.println("Receiving error");
  else
    Serial.println(msg[0]);
}

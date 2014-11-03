#include <bccm01b.h>

Bccm01b m(10);
int report = 0;

void setup(){
  Serial.begin(9600);
  m.controlSpeed(200);
}

void loop(){
  report = m.controlSpeed(256);
  Serial.println(report);
}

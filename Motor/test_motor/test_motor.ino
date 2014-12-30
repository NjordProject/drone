#include <bccm01b.h>

Bccm01b m(3);
int report = 0;
int s = 0;
int flag = 0;

void setup(){
  Serial.begin(9600);
  m.controlSpeed(200);
}

void loop(){
  if ( flag == 0 ) {
    if ( s < 255 ) {
      s++;
    } else {
      flag = 1;
    }
  }
  else {
    if (s > 0) {
      s--;
    } else {
      flag = 0;

    }
  }
  delay(100);
  Serial.println(s);
  report = m.controlSpeed(s);
}

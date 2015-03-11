#include <NewPing.h>
#include <SPI.h>
#include <RH_NRF24.h>
#include <communication.h>

#define DRONE_ID 1
#define MAX_X 20
#define MAX_Y 20

uint8_t msg[] = { DRONE_ID, 0, 0, 150, 0, 0, 0, 0, 0, 0, 0 };
uint8_t lenMsg = sizeof(msg);

Communication drone(9,10);
NewPing sonar(7,6,300);

bool ok;
bool state = false;

void setup() {
  Serial.begin(9600);
  ok = drone.initRadio();
  if(!ok)
    Serial.println("Error init radio");
}

void loop() {
  if(msg[1] > MAX_X) {
    msg[1] = 0;
    msg[2]++;
  } else {
    msg[1]++;
  }
  if(msg[2] > MAX_Y) {
    msg[2] = 0;
  }
  state = !state;
  msg[9] = sonar.ping_cm();
  ok = drone.sendMsg(msg, lenMsg, 1);
  if(!ok)
    Serial.println("Error sending msg");
  delay(100);
}

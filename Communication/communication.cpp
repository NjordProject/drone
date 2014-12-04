#include "communication.h"

bool initRadio() {
  bool state = true;
  if(!nrf24.init())
    state = false;
  if(!nrf24.setChannel(1))
    state = false;
  if(!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    state = false;
  return state;
}

bool sendMsg(uint8_t* data, uint8_t len, uint8_t channel) {
  bool state = true;
  nrf24.setChannel(channel);
  if(!nrf24.send(data, len))
    state = false;
  nrf24.waitPacketSent();
}

bool receiveMsg(uint8_t* data, uint8_t len, uint8_t channel) {
  bool state = false;
  nrf24.setChannel(channel);
  if(nrf24.waitAvailableTimeout(100)) {
    if(nrf24.recv(data, &len))
      state = true;
  }
  return state;
}

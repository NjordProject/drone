#include "communication.h"

Communication::Communication(int pin1 = 8, int pin2 = 10) : _nrf24(8,10) {
}

bool Communication::initRadio() {
  bool state = true;
  if(!_nrf24.init())
    state = false;
  if(!_nrf24.setChannel(1))
    state = false;
  if(!_nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    state = false;
  return state;
}

bool Communication::sendMsg(uint8_t* data, uint8_t len, uint8_t channel) {
  bool state = true;
  _nrf24.setChannel(channel);
  if(!_nrf24.send(data, len))
    state = false;
  _nrf24.waitPacketSent();
}

bool Communication::receiveMsg(uint8_t* data, uint8_t len, uint8_t channel) {
  bool state = false;
  _nrf24.setChannel(channel);
  if(_nrf24.waitAvailableTimeout(100)) {
    if(_nrf24.recv(data, &len))
      state = true;
  }
  return state;
}

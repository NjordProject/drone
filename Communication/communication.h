#include <SPI.h>
#include <RH_NRF24.h>

RH_NRF24 nrf24(8, 10);

bool initRadio();
bool sendMsg(uint8_t* data, uint8_t len, uint8_t channel);
bool receiveMsg(uint8_t* data, uint8_t len, uint8_t channel);

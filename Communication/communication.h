#include <SPI.h>
#include <RH_NRF24.h>

class Communication {
private:
  RH_NRF24 _nrf24;
public:
  Communication(int pin1, int pin2);
  bool initRadio();
  bool sendMsg(uint8_t* data, uint8_t len, uint8_t channel);
  bool receiveMsg(uint8_t* data, uint8_t len, uint8_t channel);
};

#include <VirtualWire.h>
const int ledPin = 9;
char *data;
int fsrAnalogPin = 0; 
int fsrReading; 
void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
  Serial.println("Ready for Tx");
}

void loop()
{
  data="1";
  fsrReading = analogRead(fsrAnalogPin);
  Serial.println(fsrReading);
  if(fsrReading>70)
  {
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  digitalWrite(ledPin,HIGH);
  Serial.println("txed");
  delay(2000);
  }
  
}

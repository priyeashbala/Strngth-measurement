

#include <VirtualWire.h>

int fsrAnalogPin = 0; 
int fsrReading; 

void setup()
{ 
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  Serial.begin(9600);
  Serial.println("Ready for Tx");
}

void loop()
{
  fsrReading = analogRead(fsrAnalogPin);
  Serial.println(fsrReading);
  if(fsrReading>40)
  {
    send("H");
    delay(1000);  
    Serial.println("Txed");
    
  }
  
}

void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}

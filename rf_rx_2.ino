#include <VirtualWire.h>
#define RELAY1 7

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message

void setup()
{
  Serial.begin(9600);
  Serial.println("Device is ready");
  // Initialize the IO and ISR 
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver
}

void loop()
{
  
    if (vw_get_message(message, &messageLength)) // Non-blocking
  
  {
    Serial.print("Received: ");
    String s;
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println(message[0]);
    if(message[0]==72)
    {
        Serial.println("working");  
        digitalWrite(RELAY1,HIGH); // This will Turn ON the relay 1
       delay(1000);
      digitalWrite(RELAY1,LOW); // This will Turn ON the relay 1

    
    }
    
    Serial.println();
  }

}

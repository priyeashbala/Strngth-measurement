  #include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

int fsrAnalogPin = 0; 
int fsrReading; 


RH_ASK driver;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
     
    fsrReading = analogRead(fsrAnalogPin);
  Serial.println(fsrReading);
  if(fsrReading>200)
  {
    function1();
    delay(1000);  
    Serial.println("Txed");
    
  }
   
}

void function1()
{
  const char *msg = "Transmitted";
  //const char *msg = "000000000000";
   if(driver.send((uint8_t *)msg, strlen(msg)))
    {
      Serial.print("Transmitter \n");
    //driver.waitPacketSent();
    //delay(1000);
    }
}

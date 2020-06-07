#define dataout 12
#define ledPin 7

 void setup()
 {
   pinMode(dataout, OUTPUT);     
   pinMode(ledPin, OUTPUT);   
   Serial.begin(9600); 
 }

 void loop()
 {
   
     digitalWrite(dataout, HIGH);
     digitalWrite(ledPin, HIGH);
     delay(2000);
     
     digitalWrite(dataout,LOW);
     digitalWrite(ledPin, LOW);
     delay(2000);
 
 }

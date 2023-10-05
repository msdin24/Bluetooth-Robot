
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 4); // RX, TX
#define led 13
void setup() 
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  while (!Serial); // wait for serial port to connect. Needed for native USB port only 


  // Set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() 
{ 
  if (mySerial.available()) 
  {
    char val = mySerial.read();
    Serial.write(val);
    
    if( val=='1')
    {
      digitalWrite(led,HIGH);
      Serial.println(val);
    }
    if( val=='0')
    {
     digitalWrite(led,LOW);
     Serial.println(val); 
    }
  }
  
  if (Serial.available()) 
  {
    mySerial.write(Serial.read());
  }
}

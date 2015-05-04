/*
  Example Bluetooth Serial Passthrough Sketch
 by: Jim Lindblom
 SparkFun Electronics
 date: February 26, 2013
 license: Public domain
 
 This example sketch converts an RN-42 bluetooth module to
 communicate at 9600 bps (from 115200), and passes any serial
 data between Serial Monitor and bluetooth module.
 */
#include <SoftwareSerial.h>  

int bluetoothTx = 1;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 0;  // RX-I pin of bluetooth mate, Arduino D3
int ledpin=13;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
char a;
void setup()
{


  
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  bluetooth.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  if(bluetooth.available())  // If the bluetooth sent any characters
  { 
    // Send any characters the bluetooth prints to the serial monitor
    a=bluetooth.read();
    if(a=='1')
    {
        digitalWrite(ledpin,1);
    }
    else if(a=='0')
    {
      digitalWrite(ledpin,0);
    }
    else
    {
      bluetooth.write("Press 0 to switch off");
    }
    
  }
  delay(100);// prepare for next data ...

}


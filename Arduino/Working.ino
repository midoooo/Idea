
#include <SoftwareSerial.h>  

int bluetoothTx = 1;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 0;  // RX-I pin of bluetooth mate, Arduino D3
int ledpin=13;
int ledpin2=14;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
char a;
void setup()
{


  
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  bluetooth.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
   pinMode(ledpin2,OUTPUT);
}

void loop()
{
  if(bluetooth.available())  // If the bluetooth sent any characters
  { 
    // Send any characters the bluetooth prints to the serial monitor
    a=bluetooth.read();
    if(a=='3')
    {
        digitalWrite(ledpin2,1);
    }
    else if(a=='4')
    {
      digitalWrite(ledpin2,0);
    }

    if(a=='1')
    {
        digitalWrite(ledpin,1);
    }
    else if(a=='2')
    {
      digitalWrite(ledpin,0);
    }
    else
    {
      bluetooth.write("Press 1,3 to switch on and 2,4 to off");
    }
    
  }
  delay(100);// prepare for next data ...

}


#include<SPI.h>
#include<Ethernet.h>
byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
IPAddress ip(10,0,0,20);
EthernetServer server(80);
String HTTP_req;
boolean LED_status=0;
void setup() {
  // put your setup code here, to run once:
 Ethernet.begin(mac,ip);
    server.begin();
    Serial.begin(9600);
    pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   EthernetClient client=server.available();
   if(client){
     boolean currentLineIsBlank=true;
     while(client.connected()){
       if(client.available()){
         char c=client.read();
         HTTP_req+=c;
         if(c=='\n' && currentLineIsBlank){
           client.println("HTTP/1.1 200 OK");
           client.println("Content-Type:text/html");
           client.println("Connection:close");
             client.println();
         client.println("<html><head><title>Garage Control</title></head>");
           client.println("<body><form method=\"get\">");
           ProcessCheckbox(client);
             client.println("</form></body></html>");
             Serial.print(HTTP_req);
             HTTP_req="";
             break;
         }
         if(c=='\n'){
           currentLineIsBlank=true;
         }
         else if(c!='\r'){
           currentLineIsBlank=false;
         }
       }
     }
     delay(1);
     client.stop();
   }
}
void ProcessCheckbox(EthernetClient cl){
  
         if(HTTP_req.indexOf("LEd2=2")>-1){
           if(LED_status){
            LED_status=0;
           }
           else
           {
             LED_status=1;
           }
         }
           if(LED_status){
             digitalWrite(2,HIGH);
             cl.println("<input type=\"checkbox\" name=\"LED2\" value=\"2\" onselect=\"submit();\">led2"); 
           }
            else
           {
             digitalWrite(2,LOW);
             cl.println("<input type=\"checkbox\" name=\"LED2\" value=\"2\" onselect=\"submit();\">led2");
           }   
           
}


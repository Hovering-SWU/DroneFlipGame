#include <string.h>  
  
///////////////////////////////////////////  
#include <SoftwareSerial.h>  // 소프트웨어 시리얼 라이브러리
    
///////////////////////////////////////////  
 
#define DEBUG true
 SoftwareSerial Serial1(10, 9);
void setup() {
 
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial1.begin(9600);
  sendData("AT+RST\r\n", 5000, DEBUG); // rst
  sendData("AT+CWJAP=\"SWU_WiFi(Free)\",\"\"\"\r\n", 15000, DEBUG); //enter name and password
}
 
void loop() {
  int key;
  sendData("AT+CWMODE=3\r\n", 11000, DEBUG); //  access point
  sendData("AT+CIFSR\r\n", 7000, DEBUG); // get ip address
  sendData("AT+CIPMUX=1\r\n", 7000, DEBUG); // configure for multiple connections
  sendData("AT+CIPSTART=4,\"TCP\",\"13.125.125.79\",52586\r\n", 5000, DEBUG); // turn on server on port 80
  
  String web = "GET Drone-Whac-A-Mole/insert_score1.php?num=20";
 
  web += "HTTP/1.1\r\n";
  web += "Host: 13.125.125.79\r\n";
  web += "\r\n";
  web += "\r\n";
  
  String cipsend = "AT+CIPSEND=";
  cipsend += 4;
  cipsend += ",";
  cipsend += String(web.length());
  cipsend += "\r\n";
  sendData(cipsend, 5000, DEBUG);
  sendData(web, 5000, DEBUG);
  String closeCommand = "AT+CIPCLOSE=";
  closeCommand += 4;// append connection id
  closeCommand += "\r\n";
  sendData(closeCommand, 3000, DEBUG);
}
 
String sendData(String command, const int timeout, boolean debug) {
  String response = "";
  Serial1.print(command); // send the read character to the esp8266
  long int time = millis();
  while ( (time + timeout) > millis()) {
    while (Serial1.available()) {
      // output to the serial window
      char c = Serial1.read(); // read the next character.
      response += c;
    }
  }
  if (debug) {
    Serial.print(response);
  }
  return response;
}

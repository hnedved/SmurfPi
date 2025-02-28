#include <OSCMessage.h>

/*
    Make an OSC message and send it over UDP
    
    Adrian Freed
 */
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

EthernetUDP Udp;

//the Arduino's IP
IPAddress ip(192, 168, 0, 121);
//destination IP
IPAddress outIp(192, 168, 0, 13);
const unsigned int outPort = 53000;
IPAddress outIp2(192, 168, 0, 14);
const unsigned int outPort2 = 8000;

 byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // you can find this written on the board of some Arduino Ethernets or shields
void setup() {
  Ethernet.begin(mac,ip);
    Udp.begin(53000);
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  //pinMode(13, OUTPUT);
}


void loop(){

    int sensorVal5 = digitalRead(5);
    int sensorVal6 = digitalRead(6);
    int sensorVal7 = digitalRead(7);
    int sensorVal8 = digitalRead(8);
    int sensorVal9 = digitalRead(9);
  //print out the value of the pushbutton
  Serial.print(sensorVal5);
  Serial.print(sensorVal6);
  Serial.print(sensorVal7);
  Serial.print(sensorVal8);
  Serial.print(sensorVal9);
  Serial.println("");
    if (sensorVal5 == HIGH) {
     //   Serial.println("Rozpojeno");
  } else {
      OSCMessage msg("/cue/4/go");
  msg.add((int32_t)analogRead(0));
    Serial.println("FlyAndPurpleSmurf");
    Serial.println("/cue/4/go");
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

      OSCMessage msg2("/button/1");
  msg2.add((int32_t)analogRead(0));
    Serial.println("/button/1");
  Udp.beginPacket(outIp2, outPort2);
    msg2.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg2.empty(); // free space occupied by message

  }
    if (sensorVal6 == HIGH) {
     //   Serial.println("Rozpojeno");
  } else {
      OSCMessage msg("/cue/5/go");
  msg.add((int32_t)analogRead(0));
  Serial.println("BigMouthLaguh");
    Serial.println("/cue/5/go");
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

        OSCMessage msg2("/button/2");
  msg2.add((int32_t)analogRead(0));
    Serial.println("/button/2");
  Udp.beginPacket(outIp2, outPort2);
    msg2.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg2.empty(); // free space occupied by message
  }
  if (sensorVal7 == HIGH) {
     //   Serial.println("Rozpojeno");
  } else {
      OSCMessage msg("/cue/6/go");
  msg.add((int32_t)analogRead(0));
    Serial.println("AzraelLaugh");
    Serial.println("/cue/6/go");
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

        OSCMessage msg2("/button/3");
  msg2.add((int32_t)analogRead(0));
    Serial.println("/button/3");
  Udp.beginPacket(outIp2, outPort2);
    msg2.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg2.empty(); // free space occupied by message
  }
  if (sensorVal8 == HIGH) {
      //  Serial.println("Rozpojeno");
  } else {
      OSCMessage msg("/cue/7/go");
  msg.add((int32_t)analogRead(0));
    Serial.println("GargamelLaugh");
    Serial.println("/cue/7/go");
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

        OSCMessage msg2("/button/4");
  msg2.add((int32_t)analogRead(0));
    Serial.println("/button/4");
  Udp.beginPacket(outIp2, outPort2);
    msg2.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg2.empty(); // free space occupied by message
  }
  if (sensorVal9 == HIGH) {
      //  Serial.println("Rozpojeno");
  } else {
      OSCMessage msg("/cue/8/go");
  msg.add((int32_t)analogRead(0));
    Serial.println("Cracoucas");
    Serial.println("/cue/8/go");
  Udp.beginPacket(outIp, outPort);
    msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

        OSCMessage msg2("/button/5");
  msg2.add((int32_t)analogRead(0));
    Serial.println("/button/5");
  Udp.beginPacket(outIp2, outPort2);
    msg2.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg2.empty(); // free space occupied by message
  }



  delay(100);
  
}
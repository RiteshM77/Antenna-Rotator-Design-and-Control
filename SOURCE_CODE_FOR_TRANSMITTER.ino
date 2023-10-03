#include <VirtualWire.h>
#define d3 2
#define d2 3
#define d1 4
#define d0 5
#define button 6
char *data;
int val;
int val0, val1, val2, val3;
int value = 0;
void setup()
{
Serial.begin(9600);
vw_set_tx_pin(12);
vw_setup(2000);
pinMode(button, INPUT_PULLUP);
pinMode(d0,INPUT_PULLUP);
pinMode(d1,INPUT_PULLUP);
pinMode(d2,INPUT_PULLUP);
pinMode(d3,INPUT_PULLUP);
}
void loop()

{
val = digitalRead(button);
val0 = digitalRead(d0);
val1 = digitalRead(d1);
val2 = digitalRead(d2);
val3 = digitalRead(d3);
if(val == LOW && value == 0)
{
data="a";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
value = 1;
}
else if(val == LOW && value == 1)
{
data="b";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
value = 0;
}
if(val3 == 1 && val2 == 1 && val1 == 1 && val0 == 1){
data="0";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();

Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 1 && val1 == 1 && val0 == 0){
data="1";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 1 && val1 == 0 && val0 == 1){
data="2";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 1 && val1 == 0 && val0 == 0){
data="3";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 0 && val1 == 1 && val0 == 1){
data="4";

vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 0 && val1 == 1 && val0 == 0){
data="5";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 0 && val1 == 0 && val0 == 1){
data="6";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 1 && val2 == 0 && val1 == 0 && val0 == 0){
data="7";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}

if(val3 == 0 && val2 == 1 && val1 == 1 && val0 == 1){
data="8";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
if(val3 == 0 && val2 == 1 && val1 == 1 && val0 == 0){
data="9";
vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();
Serial.print("data sent : ");
Serial.println(data);
delay(500);
}
delay(200);
}

#include <VirtualWire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define ledPin 6
void setup()
{
Serial.begin(9600);
vw_set_rx_pin(11);
vw_setup(2000);
pinMode(ledPin, OUTPUT);
vw_rx_start();
lcd.begin();
lcd.backlight();
lcd.clear();
}
void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
if (vw_get_message(buf, &buflen))
{
if(buf[0]==’a’)
{
digitalWrite(ledPin,HIGH);
}
else if(buf[0]==’b’)

{
digitalWrite(ledPin,LOW);
}
if(buf[0]==48){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("0");
Serial.println("0");
}
if(buf[0]== 49){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("1");
Serial.println("1");
}
if(buf[0]== 50){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("2");
Serial.println("2");
}
if(buf[0]== 51){
lcd.clear();
lcd.setCursor(0,0);
xvi
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("3");
Serial.println("3");
}
if(buf[0]== 52){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("4");
Serial.println("4");
}
if(buf[0]== 53){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("5");
Serial.println("5");
}
if(buf[0]== 54){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("6");
Serial.println("6");
}
if(buf[0]== 55){

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("7");
Serial.println("7");
}
if(buf[0]== 56){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("8");
Serial.println("8");
}
if(buf[0]== 57){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Received : ");
lcd.setCursor(11,0);
lcd.print("9");
Serial.println("9");
}
}
}

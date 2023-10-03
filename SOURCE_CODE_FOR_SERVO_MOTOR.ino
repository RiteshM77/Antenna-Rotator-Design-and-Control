#include<Servo.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo s1;
Servo s2;
int k1, k2;
#define toggle 5
#define up1 6
#define down1 7
#define up2 8
#define down2 9
void setup(){
Serial.begin(9600);
s1.attach(2);
s2.attach(3);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);

lcd.begin();
lcd.backlight();
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Antenna Rotator");
delay(2000);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Project By");
lcd.setCursor(0,1);
lcd.print("SARTHAK & RUTURAJ");
delay(1500);
lcd.scrollDisplayLeft();
delay(1500);
lcd.scrollDisplayRight();
delay(1500);
lcd.clear();
}
void loop(){
while(digitalRead(5) == 0){
int val1 = analogRead(A0);
int val2 = analogRead(A1);
k1 = map(val1,0,1023,0,180);
k2 = map(val2,0,1023,0,180);
s1.write(k1);
s2.write(k2);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle 1 = ");
lcd.setCursor(10,0);
lcd.print(k1);
lcd.setCursor(14,0);
lcd.print("°");
lcd.setCursor(0,1);
lcd.print("Angle 2 = ");
lcd.setCursor(10,1);
lcd.print(k2);
lcd.setCursor(14,1);
lcd.print("°");
}
while(digitalRead(5) == 1){
while(digitalRead(up1) == 0){
k1 += 1;
s1.write(k1);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle 1 = ");
lcd.setCursor(10,0);
lcd.print(k1);
lcd.setCursor(14,0);
lcd.print("°");
lcd.setCursor(0,1);

lcd.print("Angle 2 = ");
lcd.setCursor(10,1);
lcd.print(k2);
lcd.setCursor(14,1);
lcd.print("°");
delay(500);
}
while(digitalRead(down1) == 0){
k1 -= 1;
s1.write(k1);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle 1 = ");
lcd.setCursor(10,0);
lcd.print(k1);
lcd.setCursor(14,0);
lcd.print("°");
lcd.setCursor(0,1);
lcd.print("Angle 2 = ");
lcd.setCursor(10,1);
lcd.print(k2);
lcd.setCursor(14,1);
lcd.print("°");
delay(500);
}

while(digitalRead(up2) == 0){
k2 += 1;
s2.write(k2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle 1 = ");
lcd.setCursor(10,0);
lcd.print(k1);
lcd.setCursor(14,0);
lcd.print("°");
lcd.setCursor(0,1);
lcd.print("Angle 2 = ");
lcd.setCursor(10,1);
lcd.print(k2);
lcd.setCursor(14,1);
lcd.print("°");
delay(500);
}
while(digitalRead(down2) == 0){
k2 -= 1;
s2.write(k2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Angle 1 = ");
lcd.setCursor(10,0);
lcd.print(k1);
lcd.setCursor(14,0);
lcd.print("°");

lcd.setCursor(0,1);
lcd.print("Angle 2 = ");
lcd.setCursor(10,1);
lcd.print(k2);
lcd.setCursor(14,1);
lcd.print("°");
delay(500);
}
}

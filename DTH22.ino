#include <Wire.h> //เพิ่ม Library Wire สำหรับการสื่อสารผ่านบัส I2C เข้าสู่โปรเจค
#include <LiquidCrystal_I2C.h> //เพิ่ม Library LiquidCrystal_I2C สำหรับการควบคุมการทำงานของจอ LCD เข้าสู่โปรเจค

#include "DHT.h"  //เพิ่ม Library DHT สำหรับการเข้าสู่โปรเจค
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define DHTPIN D4 // ใช้ขา digital 4 สำหรับกสนอ่านข้อมูลจาก DHT22

DHT dht(DHTPIN, DHTTYPE); //ประกาศตัวแปล object สำหรับกสนเรียกใช้งาน DHT22

LiquidCrystal_I2C lcd(0x27, 16, 2); //ตั้งค่า LCD address เป็น 0x27 สำหรับ 16 ตัวอักษร 2 สองบรรทัด

void setup()
{
  dht.begin();
  lcd.begin();  //เริ่มต้นการติดต่อสื่อสารกับ I2C LCD
  lcd.print("Node MCU 2.0");  //แสดงข้อความ ""Node MCU 2.0""
  lcd.setCursor(0, 1);  //ย้ายตำแหน่งเคอร์เซอร์ ไปยังคอลัมน์ที่ 0 บรรทัดที่ 1
  lcd.print("Temp&Humi");  //แสดงข้อความ "Temp&Humi"
  delay(5000);
}

void loop()
{
  delay(2000); //หน่วงเวลา 2 วินาที
  float h = dht.readHumidity(); //อ่าค่าความชื่นเข้าสู่ตัวแปล h
  float t = dht.readTemperature(); //อ่านค่าอุณหภูมิเข้าสู่ตัวแปล t
    
  if (isnan(h) || isnan(t)) //ตรวจสอบการอ่านค่า ถ้าล้มแหลวให้กลับไปอ่านใหม่
  {
    return;
  }
  //แสดงค่าออกทาง LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(h);
  lcd.print(" %");
}

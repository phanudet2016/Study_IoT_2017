#include <LiquidCrystal_I2C.h>

#include <Wire.h> //เพิ่ม Library Wire สำหรับการสื่อสารผ่านบัส I2C เข้าสู่โปรเจค
#include <LiquidCrystal_I2C.h> //เพิ่ม Library LiquidCrystal_I2C สำหรับการควบคุมการทำงานของจอ LCD เข้าสู่โปรเจค

LiquidCrystal_I2C lcd(0x27, 16, 2); //ตั้งค่า LCD address เป็น 0x27 สำหรับ 16 ตัวอักษร 2 สองบรรทัด

void setup()
{
  lcd.begin();  //เริ่มต้นการติดต่อสื่อสารกับ I2C LCD
  lcd.print("Hello (^__^)");  //แสดงข้อความ ""Node MCU 2.0""
  lcd.setCursor(0, 1);  //ย้ายตำแหน่งเคอร์เซอร์ ไปยังคอลัมน์ที่ 0 บรรทัดที่ 1
  lcd.print("Node MCU 2.0");  //แสดงข้อความ "Temp&Humi"
}

void loop()
{
  //ไม่มีการทำงานในส่วนนี้
}

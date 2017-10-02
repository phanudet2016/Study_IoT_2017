const int Node_LED = 5; //กำหนดให้ Node_LED แทนชื่อ digital I/O ขาที่ 2 ของ NodeMCU (Built in LED)
void setup() 
{
  // put your setup code here, to run once:
  pinMode(Node_LED,OUTPUT); //กำหนดให้ Node_LED มีรูปแบบการทำงานในโหมดเอาต์พุต
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(Node_LED,HIGH);  //กำหนดให้ส่งสัญญาณเอาต์พุต HIGH (3.3V) ออกทางขา Node_LED 
  delay(200); //หน่วงเวลา 200 มิลลิวินาที
  digitalWrite(Node_LED,LOW); //กำหนดให้ส่งสัญญาณเอาต์พุต LOW (0V) ออกทางขา Node_LED 
  delay(200); //หน่วงเวลา 200 มิลลิวินาที

}

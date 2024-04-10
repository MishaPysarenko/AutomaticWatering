#include <string.h>

//#include <avr/wdt.h>

//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей   A4 - SDA : A5 - SCL

#include <GyverEncoder.h>
#define CLK A1
#define DT A2
#define SW A3
Encoder enc(CLK, DT, SW);
//--------------------------------------------------------------------------------
#define D1 2//
#define D2 3//
#define D3 4//
//--------------------------------------------------------------------------------
unsigned short int cursor = 0; //курсор в меню
unsigned short int Rele[] = {R1,R2,R3,R4,R5};
unsigned short int Sensor[] = {D1,D2,D3,D4,D5,D6,D7};
String menuList[3] = {"Algortm 1", "Algortm 2", "Algortm 3"};
//-----------------------технические функции--------------------------------------
void MainLogic(){
  switch(cursor)
  {
    case 0://Алгоритм 1

    break;
    case 1://Алгоритм 2

    break;
    case 2://Алгоритм 3

    break;
    }
}
//------------------------функкции отрисовки---------------------------------------
void DrawMenu(){

}
//---------------------------------------------------------------------------------
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A0,OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setBacklight(255);
  lcd.setCursor(0, 0);
  lcd.print("Check");
  delay(1000);
  enc.setType(TYPE2);//настройка типа енкодара ------------------------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  if(!chekWork())
  {
    lcd.setCursor(0, 0);
    lcd.print("Reboot System");
    delay(1000);
    while(1){
      
    }
  }
  lcd.print("Start System");
  delay(1000);
  DrawMenu();
}

void loop() {
  enc.tick();
  if(enc.isTurn())
  {
    if(enc.isRight())cursor++;
    else cursor--;
    if(cursor > 2)cursor = 0;
    DrawMenu();
  }
  if(enc.isPress())
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(menuList[(cursor)]);
    MainLogic();
    DrawMenu();
  }
}

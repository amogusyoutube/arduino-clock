/* 
 Тестирование производилось на Arduino IDE 1.6.11
 Дата тестирования 20.0509.2016г.
*/
int time_h = 10;
int time_m = 41;
#include <LiquidCrystalRus.h>

LiquidCrystalRus lcd(7, 6, 5, 4, 3, 2);   

void setup()
{
 lcd.begin(16, 2);  // Инициализирует LCD 16x2
}

void loop()
{
  if(time_h == 24){
    time_h = 0;
    time_m = 0;
  }
  if(time_m == 60){
   ++time_h;
   time_m = 0;
  }
 
  lcd.setCursor(0,2);
  lcd.print("Decamber");
  lcd.setCursor(10, 0);
  lcd.print(2023);
  if(time_h < 10){
    lcd.setCursor(0,0); // Установить курсор на первыю строку
  lcd.print(0);
  lcd.setCursor(1,0);
  lcd.print(time_h);
  lcd.setCursor(2,0); 
  lcd.print(":");
  }
  else{
    lcd.setCursor(0,0); // Установить курсор на первыю строку
  lcd.print(time_h);
  lcd.setCursor(2,0); 
  lcd.print(":"); 
  }
 
 
  if (time_m < 10){
    lcd.setCursor(3,0);
    lcd.print(0);
    lcd.setCursor(4,0);
  lcd.print(time_m);
  }
  else{
    lcd.setCursor(3,0);
  lcd.print(time_m);
  }
  
 delay(60000);
 time_m ++;
}

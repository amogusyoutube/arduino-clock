/* 
 Тестирование производилось на Arduino IDE 1.6.11
 Дата тестирования 20.0509.2016г.
*/
const char now[] = __TIME__;
 
   byte hour =  atoi(&now[0]);
   byte minute = atoi(&now[3]);
   byte seconds = atoi(&now[6]);
byte mes = 2;
byte time_h = hour;
byte time_m = minute;
byte day_m = 17;
int day_in_year = 0;
long int year = 2024;
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   
byte bokal[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00100,
  B00100,
  B11111
};
void setup()
{
  lcd.createChar(1, bokal);
 lcd.begin(16, 2);  // Инициализирует LCD 16x2
 
}

void loop()
{
  if (day_in_year == 366){
  time_h = 0;
  mes = 1;
  time_m = 0;
  day_in_year = 0;
    ++year;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Happy new year!");
    lcd.setCursor(0,2);
    lcd.write(1);
    delay(60000);
    lcd.clear();
    ++time_m;
   
    
  }
  if(day_m == 31 &&  mes != 4 && mes != 6 && mes != 8 && mes != 10 ){
  mes++;
  }
  if (day_m == 28 && mes == 2 && year != 2024 ){
    mes++;
    day_in_year = 0;
  }
  
  if(time_h == 24){
    time_h = 0;
    time_m = 0;
	 ++day_m;
	 ++day_in_year;
  }
  if(time_m == 60){
   ++time_h;
   time_m = 0;
  }
	
  
 
  lcd.setCursor(0,2);
  lcd.print(day_m);
  lcd.setCursor(2,2);
  lcd.print("/");
  lcd.setCursor(3,2);
  lcd.print(mes);
  lcd.setCursor(7, 1);
  lcd.print(year);
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

#include <TFT.h> // библиотека для работы с TFT
#include <SPI.h>
#include <EEPROM.h>

// объявление выводов для Arduino 
#define CS   10
#define DC   9
#define RESET  8  
 

 
TFT myScreen = TFT(CS, DC, RESET);
// Начальная позиция точки - это середина экрана
int xPos = 80;
int yPos = 64;
 
// направление и скорость
int xDir = 1;
int yDir = 1;
 
// переменные для отслеживания позиции точки
int xPrev = xPos;
int yPrev = yPos;
// переменная для хранения прошедшего времени
long counter = 0;
// массив символов для вывода времени на экран
char printout[6];
void setup() {
  // put your setup code here, to run once:
  myScreen.begin();  
  myScreen.setRotation(0);
  myScreen.background(0,0,0);  // очищаем экран, заливая его черным цветом
  myScreen.stroke(20,255,20); //text and elements color 
  myScreen.setTextSize(2);
  myScreen.text("Run for:",1,0);
  myScreen.text("seconds",1,40);  
  // увеличиваем размер шрифта для текста, выводимого в блоке loop() 
  myScreen.setTextSize(3);
  delay(1000);  // небольшая интригующая пауза
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 // получаем текущее время, прошедшее с момента запуска программы
    counter = millis();
    // преобразовываем его в строку
    String elapsedTime = String(counter/1000);
    // добавляем в массив
    elapsedTime.toCharArray(printout,5);
    // выводим на экран и стираем
    myScreen.stroke(255,255,255);
    myScreen.text(printout,5,17);
    delay(1000);
    myScreen.stroke(0,0,0);
    myScreen.text(printout,5,17);
}

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h> // 블루투스
 
#define BT_RXD 8
#define BT_TXD 7
SoftwareSerial bluetooth(BT_RXD, BT_TXD);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

unsigned long time_previous, time_current;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  mlx.begin();  
  time_previous = millis();
}

void loop() {  
    time_current = millis();
   
   int temp = mlx.readObjectTempC();
   
   if(time_current - time_previous >= 1000){
       bluetooth.println(temp);
         if (bluetooth.available()) {       
    Serial.write(bluetooth.read());
  }
   }
   

  if (Serial.available()) {         
    bluetooth.write(Serial.read());
  }

 
}

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(3, 4);
int LED = 8;
int FSR = A3;
int value = 0; // FSR강도를 받는다.
int totalCount = 0; // 압박강도가 일정 수치 이상임을 감지하여 개수를 센다.
int count = 0;
bool flag = false; // 일정 수준의 강도가 가해면 on해서 count를 세는데 사용된다.
unsigned long past = 0;
byte start=0;
byte cmp = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("CPR START!!");
  BTSerial.begin(9600);  // set the data rate for the BT port
}

void loop()
{
  if (BTSerial.available()) {        // 블루투스에서 보낸 내용은 시리얼모니터로 전송
    start = BTSerial.read();
    Serial.write(start);
  }
  if (start != cmp){
  value = analogRead(FSR);
  //  Serial.println(value);
  if (value > 100) {
    digitalWrite(LED, HIGH);
    flag = true;
    BTSerial.print(value);
    BTSerial.print(",");
    Serial.print("pressure : ");
    Serial.println(value);
  }
  else {
    digitalWrite(LED, LOW);
    if (flag == true) {
      count += 1;
      totalCount += 1;

      Serial.print("count : ");
      Serial.println(count);

      BTSerial.println(totalCount);
//      BTSerial.println(count);
//      BTSerial.print(",");
//      BTSerial.println();

      flag = false;
    }
  }
  unsigned long now = millis();
  //  10초마다 얼마나 압박을 가했는지 출력한다.
  if (now - past >= 10000) {
    past = now;
    Serial.print("10초 동안 가한 압박 수 : ");
    Serial.println(count);
//    totalCount += count;
    delay(10);

    Serial.print("전체 가한 압박 수 : ");
    Serial.println(totalCount);

    //    분당 100~120를 해야함으로 10초당 17~20회를 해야한다.
    if (count >= 17 && count <= 20) {
      Serial.println("현 속도 => 적당함");
    }
    else if (count < 17) {
      Serial.println("현 속도 => 느림");
    }
    else {
      Serial.println("현 속도 => 빠름");
    }
    count = 0;

    //    10초당 가한 압력의 평균을 구해서 이완이 필요한지 약한지 좋은지 판단을 하여 출력한다.

    //    기도가 확보되었는지를 자이로센서를 통해서 확인한 후에 출력


  }
  }
  delay(100);
  if (Serial.available()) {           // 시리얼모니터에서 보낸 내용은 블루투스로 전송
    BTSerial.write(Serial.read());
  }
}

# 아두이노 Gyro센서와 FSR센서를 통한 실시간CPR 교육 어플리케이션
최근 들어 많은 기관에서 심폐소생술(Cardio-Pulmonary Resuscitation, CPR)에 대해 많은 교육을 진행하고 있다. 
실제로 일반인들이 심폐소생술을 사용하여 위급한 환자의 생명을 구한 경우가 매 해 증가하고 있다. 하지만 잘못된 심폐소생술은 환자를 더욱 위태롭게 할 수 있다. 
심폐소생술에서 흉부압박의 강도는 성인은 5cm깊이로 강하게 눌러야 하고 분당 압박 횟수는 100-120회가 되어야한다.
교육을 받았더라도 압박의 정도나 분당 횟수는 알기 어렵다. 또한 많은 이들이 심폐소생술에 집중하여 기도확보에 신경을 쓰지 못한다. 
본 프로젝트은 CPR마네킹에 압력센서와 Gyro센서를 부착하여 압박정도와 강도, 기도확보 여부를 확인함으로써 정확한 CPR교육을 진행하도록 도와주는 어플리케이션을 제안한다.
## CPR 문제점
1. 긴박한 심폐소생술 중에 심정지 리듬을 확인하기 위해 흉부 압박을 빈번하게 중단하면 심장 및 뇌의 허혈성 손상을 더욱더 증가시킨다.->흉부 압박 중 제세동이 필요한 리듬을 인지하는 비접촉식 알고리즘 개발중 https://post.naver.com/viewer/postView.nhn?volumeNo=28800746&memberNo=49312582
2. 일반인의 경우 인공호흡을 정확히 실시하지 못하기때문에 가슴압박만 한것과 인공호흡까지 한것, 두 개의 소생률에 큰 차이가 없다.(2015 심폐소생술 가이드라인)
3. 시카고 병원 내에서 시행된 67건의 cpr을 분석한 결과 흉부압박이 분당 90회 이하이거나(26%) 압박깊이가 너무 얕거나(37%) 인공호흡 횟수가 분당 20회(61%)로 지나치게 많은것으로 나타났다. https://www.khanews.com/news/articleView.html?idxno=464

## 아이디어
1. 압박부위에 압력센서를 부착 후 압력을 측정하여 분당 100~120회를 할 수 있도록 도와주고, 압력은 충분한지를 측정하여 CPR 교육을 잘 진행하도록 도와준다.
2. 심폐소생술을 실시할 경우 가슴압박에 집중하여 기도확보를 등안시 하는 경우가 있다. 이를 자이로 센서를 통해 교육 도중 기도 확보 여부를 알려준다.
3. 인공호흡의 경우에 일반인은 인공호흡을 하지 않는 경우와 하는 경우의 소생성공률의 차이가 없다. 그러므로 인공호흡은 하지 않는 걸로 가정한다.

## UI 기본 틀
아래 기사에서 처럼 CPR교육을 진행하는 도중에 자신이 얼마나 정확하게 진행하고 있는지를 실시가능로 확인 가능하도록 UI를 디자인할 계획이다.<br>
http://www.safetimes.co.kr/news/articleView.html?idxno=94064

## Arduino Project contents

### 1. Project 방향
 1. CPR기계에 아두이노를 연결하여 CPR교육을 더욱 원활하게 하여 소생성공률을 높힌다.
 2. 교육에 흥미를 가지도록 시간별로 압박 강도와 기도 확보를 자이로 센서와 압박센서를 어플리케이션을 통해 실시간으로 알려준다.
 3. 또한 설정한 시간동안 CPR 교육을 진행한 후 점수를 통해 진행한 CPR training의 정확도를 나타낸다.
### 2. 동기
  1. 심페소생술 시행 시 정확하게 진행이 되지 않을 시 환자에게 더욱 안 좋을 수 있다.
  2. 기도확보가 잘 되지 않거나 압박강도가 정확하지 않은 경우가 많이 있다.
  3. cpr교육에 흥미를 느끼고 전체 점수를 통해서 자신이 얼마나 잘했는지를 평가하여 CPR training의 정확도를 높힌다. 이로 인해 소생 성공률을 높힐 수 있다.
### 3. 흐름도
   ![img.png](img.png)

### 4. 자이로 센서
   ![img_2.png](img_2.png)<br>
   위 사진은 자이로 센서로 자이로스코프가 내장된 물체가 회전 운동을 하면 생기는 회전 반발력을 측정하여 전기 신호로 바꾸어 출력하고 이를 수치화하여 활용하게 된다. 이 프로젝트에서는 마네킹의 머리에 Gyro센서를 부착하여 기도확보 여부를 판단할 수 있게한다.
### 5. 압력 센서
   ![img_1.png](img_1.png)<br>
   위 사진은 FSR402압력센서로 물리적인 힘, 무게에 따라 저항 값이 바뀌는 성질을 이용한 센서로 압력 센서라고도 한다. 이 프로젝트에서 CPR교육 중 압박 강도를 측정하기 위해서 사용되었다.
### 6. 블루투스 모듈
   ![img_3.png](img_3.png)<br>
   위 사진은 블루투스 통신을 가능하게 하는 모듈로 아두이노에서 시리얼통신을 이용하여 데이터 값을 주고받을 수 있는 모듈이며, 10미터 정도에서 무선으로 데이터를 보내거나 받을 수 있다. 이 프로젝트에서는 자이로 센서와 압력 센서의 모듈의 센서 값을 HC-6을 통해 어플리케이션으로 받아서 CPR교육을 진행한다.
### 7. 압력센서와 자이로센서와 블루투스를 연동하여 핸드폰으로 출력
   ![img_4.png](img_4.png)<br>
   위 사진은 설정한 시간동안 CPR교육을 진행하는 도중 압력값과 시행 횟수를 보여준다.
### 8. 참고 문헌
[1] 대한심폐소생협회. 가슴압박소생술 시행방법 https://www.kacpr.org/page/page.php?category_idx=3&category1_code=1247206302&category2_code=1527742406&page_idx=1120<br>
[2] 김선우, 용범순, 전용찬, 이용환, 문상국(2021). 아두이노와 블루투스 모듈을 이용한 스마트폰으로 제어하는 원격 도어락<br>
[3] 이영권, 오경식, 안동순(2017). Arduino Bluetooth 통신을 이용한 사물 인터넷(IoT)<br>
[4] Android, “android studio Documentation”, https://developer.android.com/guide/topics/connectivity/bluetooth?hl=ko


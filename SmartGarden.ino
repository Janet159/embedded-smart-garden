//라이브러리 설정
#include <LiquidCrystal.h> //lcd라이브러리
#include <DHT.h> //온습도 센서 라이브러리
#include <Adafruit_NeoPixel.h> //네오 픽셀 라이브러리
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

//변수로 핀 설정
const int light_sensor=A15; //조도 센서 
const int th_sensor=A14; //온습도 센서
const int hit_sensor=A13; //충격 센서
const int soil_sensor=A12; //토양수분센서
const int neo_pin=34; //네오 픽셀 핀 지정
const int num_neo=8; //네오 픽셀의 개수 지정
const int DHTTYPE=DHT11; //온습도 센서 타입 설정
const int RED_LED=46; //RED_LED
const int water_motor1=7; //모터 드라이버의 작동 제어 PWM 핀
const int water_motor2=6; //모터 드라이버의 회전 방향 제어
const int water_motor3=5; //모터 드라이버의 회전 방향 제어
const int button_pin1=42; //버튼1
const int button_pin2=43; //버튼2
const int buzzerPin=47; //BUZZER
const int wind_motor1=2; //모터 드라이버의 작동 제어 PWM 핀
const int wind_motor2=14; //모터 드라이버의 회전 방향 제어
const int wind_motor3=15; //모터 드라이버의 회전 방향 제어
Adafruit_NeoPixel strip = Adafruit_NeoPixel
(num_neo, neo_pin, NEO_GRB + NEO_KHZ800); //NeoPixel LED 스트립을 초기화하고 설정
DHT dht(th_sensor, DHTTYPE); //DHT센서 초기화

//워터 펌프 모터 작동 함수
void waterpump_start(){
  digitalWrite(water_motor1, HIGH); //모터 작동
  digitalWrite(water_motor2, HIGH); //회전 방향 설정 HIGH
  digitalWrite(water_motor3, LOW); //회전 방향 설정 LOW
}
//워터 펌프 모터 정지 함수
void waterpump_stop(){
  digitalWrite(water_motor1, LOW); //모터 끔
  digitalWrite(water_motor2, LOW); //회전 방향 설정 LOW
  digitalWrite(water_motor3, LOW); //회전 방향 설정 LOW
}

//선풍기 모터 작동 함수
void wind_start(){
  digitalWrite(wind_motor1, HIGH); //모터 작동
  digitalWrite(wind_motor2, HIGH); //회전 방향 설정 HIGH
  digitalWrite(wind_motor3, LOW); //회전 방향 설정 LOW
}
//선풍기 모터 정지 함수
void wind_stop(){
  digitalWrite(wind_motor1, LOW); //모터 끔
  digitalWrite(wind_motor2, LOW); //회전 방향 설정 LOW
  digitalWrite(wind_motor3, LOW); //회전 방향 설정 LOW
}



// 피에조 부저에서 경고음 발생
void WarningSound() {
  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, 1000); //1000Hz주파수
    delay(400);
    tone(buzzerPin, 800); //800Hz주파수
    delay(400);
  }
  noTone(buzzerPin); // 부저 끄기
}

void setup() {
  pinMode(light_sensor, INPUT_PULLUP); //조도 센서핀 입력 양극 가능해서 PULLUP형태로 연결(반비례)
  pinMode(hit_sensor, INPUT); //충격 센서핀 입력
  pinMode(soil_sensor, INPUT); //토양 습도 센서핀 입력
  pinMode(neo_pin, OUTPUT); //네오 픽셀핀 출력
  pinMode(RED_LED, OUTPUT); //빨간 LED핀 출력
  pinMode(water_motor1, OUTPUT); //모터 작동 설정핀 출력
  pinMode(water_motor2, OUTPUT); //모터 회전 방향핀 출력
  pinMode(water_motor3, OUTPUT); //모터 회전 방향핀 출력
  pinMode(button_pin1, INPUT_PULLUP); //스위치1핀 입력 풀업 저항, 외부에서 LOW로 당겨지지 않으면 HIGH 유지
  pinMode(button_pin2, INPUT_PULLUP); //스위치2핀 입력 풀업 저항, 외부에서 LOW로 당겨지지 않으면 HIGH 유지
  pinMode(buzzerPin, OUTPUT); //부저핀 출력
  pinMode(wind_motor1, OUTPUT); //모터 작동 설정핀 출력
  pinMode(wind_motor2, OUTPUT); //모터 회전 방향핀 출력
  pinMode(wind_motor3, OUTPUT); //모터 회전 방향핀 출력

  dht.begin(); //온습도 센서 초기화

  Serial.begin(9600);
  //네오 픽셀 설정
  strip.begin();  // 네오 픽셀 초기화
  strip.show();   // 네오 픽셀을 초기 상태로 설정
  strip.setBrightness(230); //네오픽셀 밝기 조절

  //lcd 인트로 출력
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Smart");
  delay(1000);
  lcd.setCursor(8,0);
  lcd.print("Garden");
  delay(1000);
  lcd.setCursor(1,1);
  lcd.print("Made By YE JI!");
  delay(2000);
  lcd.clear();

}

void loop() {
  //센서 값 측정
  int light_value=analogRead(light_sensor); //조도 센서 값 측정
  int hit_value=analogRead(hit_sensor); //충격 센서 값 측정
  float soil_value=analogRead(soil_sensor); //토양 습도 센서 값 측정
  int soil_value_per=map(soil_value, 0, 1023, 0, 100); //토양 습도 값을 퍼센트로 변경
  int h_value = dht.readHumidity(); //온습도 센서에서 습도 값 측정
  delay(1000);
  int t_value = dht.readTemperature(); //온습도 센서에서 온도 값 측정
  delay(1000);
  int button_value1=digitalRead(button_pin1); //버튼 핀의 값 불러온다
  int button_value2=digitalRead(button_pin2); //버튼 핀의 값 불러온다
  

  //시리얼 모니터 센서값 설정
  Serial.println(soil_value_per);
  

  //LCD에 출력 토양 습도 값
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("M: ");
  lcd.print(soil_value_per);
  lcd.print("%");

  //LCD에 출력 조도 값 출력
  lcd.setCursor(8,0);
  lcd.print(" L: ");
  lcd.print(light_value);
   
  //LCD에 출력 온도 값 출력
  lcd.setCursor(0,1);
  lcd.print("T: ");
  lcd.print(t_value,1);


  //LCD에 출력 습도 값 출력
  lcd.setCursor(8,1);
  lcd.print(" H: ");
  lcd.print(h_value);
  lcd.print("%");

  //조도센서 값에 따른 네오 픽셀 켜기
  if(light_value<40) {
    for(int i=0; i<num_neo; i++){
    strip.setPixelColor(i, 255, 255, 255); //흰색 출력
    }
    strip.show(); //설정한 색상을 neopixel에 표시
    } else {
    for (int i = 0; i < num_neo; i++) {
    strip.setPixelColor(i, 0, 0, 0); // 모든 픽셀의 색상을 끄기 (검은색)
    }
    strip.show(); // neopixel 업데이트
    }
  delay(1000);

  //충격에 따라 RED_LED켜기
  if(hit_value>800){ //충격값이 800이상일 때
    digitalWrite(RED_LED, HIGH); //경고등 
    WarningSound(); // 경고음 
  }else{
    digitalWrite(RED_LED, LOW);
  }


  //토양습도 값에 따라 워터 펌프 작동 (값이 높을수록 습함)
  if(soil_value_per<70 && button_value2 == HIGH){
    waterpump_start();
  }
  else{
    waterpump_stop();
  }

 //첫번째 스위치를 누르면 자기소개, 날씨와 온도 알려줌
  if(button_value1==LOW){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("HELLO!");
    delay(1000);
    lcd.setCursor(3,1);
    lcd.print("I'm KEVIN");
    delay(3000);
    if(-10<=t_value && t_value<15){ //-10~14일 때 Cold!
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Today Weather is");
      delay(2000);
      lcd.setCursor(6,1);
      lcd.print("Cold!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Temperature is");
      delay(2000);
      lcd.setCursor(3,1);
      lcd.print(String(t_value));
      lcd.setCursor(6,1);
      lcd.print("degrees");
      
    }
    else if(15<=t_value && t_value<=25){ //15~25일 때 Nice!
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Today Weather is");
      delay(2000);
      lcd.setCursor(6,1);
      lcd.print("Nice!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Temperature is");
      delay(2000);
      lcd.setCursor(3,1);
      lcd.print(String(t_value));
      lcd.setCursor(6,1);
      lcd.print("degrees");
      
    }
      else if(25<t_value && t_value<=40){ //26~40일 때 HOT!
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Today Weather is");
      delay(2000);
      lcd.setCursor(6,1);
      lcd.print("HOT!");
      delay(2000);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Temperature is");
      delay(2000);
      lcd.setCursor(3,1);
      lcd.print(String(t_value));
      lcd.setCursor(6,1);
      lcd.print("degrees");
      
    }
  }

  if(button_value2==LOW){ //button2가 눌리면 선풍기가 작동
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("WIND START");
    wind_start();
    delay(5000);
    wind_stop();
  }
}

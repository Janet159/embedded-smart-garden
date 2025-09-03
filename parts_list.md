# Parts List - Smart Garden Embedded System 🌱

본 프로젝트에서 사용된 센서, 액추에이터, 모듈, 주변기기 목록입니다.  
각 기능별 준비물, 전체 부품 목록, 핀맵 정보를 정리했습니다.  
(📸 *부품 사진은 docs 폴더에 저장 후 아래 경로 맞춰주세요.*)

---

## 기능별 준비물

| 기능 | 설명 | 필요 부품 |
|------|------|-----------|
| ① 자동 급수 | 토양 습도에 따라 워터 펌프 작동 | ![soil](./docs/soil_sensor.jpg) 토양 습도 센서, ![motor](./docs/motor_driver.jpg) 모터 드라이버, ![pump](./docs/water_pump.jpg) 워터 펌프, 호스, 건전지(외부 전력) |
| ② 환경 정보 표시 | LCD에 토양 습도, 온도, 습도, 조도 출력 | ![lcd](./docs/lcd.jpg) LCD 16x2, 토양 습도 센서, ![vr](./docs/variable_resistor.jpg) 가변 저항, ![dht](./docs/dht11.jpg) DHT11 온습도 센서, ![light](./docs/light_sensor.jpg) 조도 센서 |
| ③ 자동 조명 | 어두워지면 네오픽셀 점등 | 조도 센서, ![neo](./docs/neopixel.jpg) 네오픽셀 |
| ④ 바람 공급 | 씨앗 수정/CO₂ 공급용 선풍기 | ![fan](./docs/fan.jpg) 선풍기 팬, DC 모터, 모터 드라이버, 건전지, ![switch](./docs/tact_switch.jpg) 텍트 스위치 |
| ⑤ 경고 시스템 | 충격 감지 시 경고음/경고등 | ![shock](./docs/shock_sensor.jpg) 충격 센서, ![led](./docs/red_led.jpg) 빨간 LED, ![buzzer](./docs/buzzer.jpg) 부저 |
| ⑥ 소통 창구 | LCD로 인사/온도 메시지 출력 | LCD, 가변 저항, DHT11, 텍트 스위치 |

---

## 전체 부품 목록

- Arduino Mega 2560 (MCU 보드) ![arduino](./docs/arduino_mega.jpg)  
- LCD 16x2 ![lcd](./docs/lcd.jpg)  
- DHT11 온습도 센서 ![dht](./docs/dht11.jpg)  
- 조도 센서 (CDS) ![light](./docs/light_sensor.jpg)  
- 토양 습도 센서 ![soil](./docs/soil_sensor.jpg)  
- 충격 센서 ![shock](./docs/shock_sensor.jpg)  
- NeoPixel (Adafruit WS2812, 8개) ![neo](./docs/neopixel.jpg)  
- 모터 드라이버 ![motor](./docs/motor_driver.jpg)  
- 워터 펌프 + 실리콘 호스 ![pump](./docs/water_pump.jpg)  
- DC 모터 + 팬 ![fan](./docs/fan.jpg)  
- 빨간 LED ![led](./docs/red_led.jpg)  
- 피에조 부저 ![buzzer](./docs/buzzer.jpg)  
- 텍트 스위치 (2개) ![switch](./docs/tact_switch.jpg)  
- 가변 저항 ![vr](./docs/variable_resistor.jpg)  
- 점퍼 케이블 (M-M, M-F, F-F) ![jumper](./docs/jumper.jpg)  
- 브레드보드 ![breadboard](./docs/breadboard.jpg)  
- 외부 전력 (건전지 팩 or 아답터) ![battery](./docs/battery.jpg)  

---

## 핀맵 (Pin Map)

| 핀 번호 | 연결 부품 | 설명 |
|---------|-----------|------|
| A15 | 조도 센서 | 주변 밝기 감지 |
| A14 | DHT11 | 온도/습도 측정 |
| A13 | 충격 센서 | 진동/충격 감지 |
| A12 | 토양 습도 센서 | 토양 수분 측정 |
| 34  | NeoPixel | 자동 조명 제어 |
| 46  | RED LED | 경고등 |
| 47  | 부저 | 경고음 출력 |
| 7/6/5 | 워터 펌프 모터 | 모터 드라이버 제어 (PWM + 방향) |
| 2/14/15 | 선풍기 모터 | 모터 드라이버 제어 (PWM + 방향) |
| 42 | 버튼1 | 자기소개/날씨 표시 트리거 |
| 43 | 버튼2 | 선풍기 작동 트리거 |
| 22–27 | LCD | 데이터 및 제어핀 |

---

## 참고 이미지

- [Wiring Diagram](./docs/wiring_diagram.png)  
- (선택) [Schematic Overview](./docs/schematic.pdf)

---

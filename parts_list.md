# Parts List - Smart Garden Embedded System 🌱

본 프로젝트에서 사용된 센서, 액추에이터, 모듈, 주변기기 목록입니다.  
각 기능별 준비물, 전체 부품 목록, 핀맵 정보를 정리했습니다.  


---

## 기능별 준비물

| 기능 | 설명 | 필요 부품 |
|------|------|-----------|
| ① 자동 급수 | 토양 습도에 따라 워터 펌프 작동 | 토양 습도 센서, 모터 드라이버, 워터 펌프, 호스, 건전지(외부 전력) |
| ② 환경 정보 표시 | LCD에 토양 습도, 온도, 습도, 조도 출력 | LCD 16x2, 토양 습도 센서, 가변 저항, DHT11 온습도 센서, 조도 센서 |
| ③ 자동 조명 | 어두워지면 네오픽셀 점등 | 조도 센서, 네오픽셀 |
| ④ 바람 공급 | 씨앗 수정/CO₂ 공급용 선풍기 | 선풍기 팬, DC 모터, 모터 드라이버, 건전지, 텍트 스위치 |
| ⑤ 경고 시스템 | 충격 감지 시 경고음/경고등 | 충격 센서, 빨간 LED, 부저 |
| ⑥ 소통 창구 | LCD로 인사/온도 메시지 출력 | LCD, 가변 저항, DHT11, 텍트 스위치 |

---

## 전체 부품 목록

- Arduino Mega 2560 (MCU 보드)<br>
  <img src="https://github.com/user-attachments/assets/f27a3dad-9a50-45ea-848d-8b2233cbfc40" width="300" />

- LCD 16x2<br>
  <img src="https://github.com/user-attachments/assets/bbdd244b-31e8-4fef-a9c7-ad1d42a50562" width="220" />

- DHT11 온습도 센서<br>
  <img src="https://github.com/user-attachments/assets/0c5bc158-4ce0-4370-ab8c-885a2335de63" width="220" />

- 조도 센서 (CDS)<br>
  <img src="https://github.com/user-attachments/assets/c11a7cb8-2f75-460c-b41b-a925487dd170" width="220" />

- 토양 습도 센서<br>
  <img src="https://github.com/user-attachments/assets/c973c7f1-f48f-4b51-84ec-2acd44b89f62" width="220" />

- 충격 센서<br>
  <img src="https://github.com/user-attachments/assets/9d7e940f-57ce-479d-8fcd-33de2f6ef44b" width="220" />

- NeoPixel (Adafruit WS2812, 8개)<br>
  <img src="https://github.com/user-attachments/assets/b7ea67de-342c-4f35-bbf5-67d4dc4d67c3" width="220" />

- 모터 드라이버<br>
  <img src="https://github.com/user-attachments/assets/c9839bae-318f-4623-be60-1da76d4a4fea" width="220" />

- 워터 펌프 + 실리콘 호스<br>
  <img src="https://github.com/user-attachments/assets/7c31bdae-8408-4c9f-b857-4a82268f41b6" width="220" />
  <img src="https://github.com/user-attachments/assets/f686f9de-d3af-482a-b987-d6cca165d899" width="220" />

- DC 모터 + 팬<br>
  <img src="https://github.com/user-attachments/assets/752d6fdc-3d1d-4731-a80f-f171a9e26427" width="220" />
  <img src="https://github.com/user-attachments/assets/85b413fc-6aae-4376-8bcc-474950fce517" width="220" />

- 빨간 LED<br>
  <img src="https://github.com/user-attachments/assets/338710b3-2824-4d61-a3c9-b3257036e26a" width="220" />

- 피에조 부저<br>
  <img src="https://github.com/user-attachments/assets/0a5d54c6-218d-4817-b6c9-ae4dc4765c7b" width="220" />

- 텍트 스위치 (2개)<br>
  <img src="https://github.com/user-attachments/assets/f9aaa611-a409-48ed-996e-afbf23aa389b" width="220" />

- 가변 저항<br>
  <img src="https://github.com/user-attachments/assets/288696fc-dad4-4ef4-b2ac-626f7d709469" width="220" />

- 점퍼 케이블 (M-M, M-F, F-F)<br>
  <img src="https://github.com/user-attachments/assets/5b564d67-0211-4307-b972-5f1ba07d4956" width="220" />

- 브레드보드<br>
  <img src="https://github.com/user-attachments/assets/170e9de2-37cb-4b16-8596-f7911e9f126d" width="300" />

- 외부 전력 (건전지 팩 or 아답터)<br>
  <img src="https://github.com/user-attachments/assets/1784638c-d77a-40d2-8cca-fe07206389cb" width="220" />


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

---



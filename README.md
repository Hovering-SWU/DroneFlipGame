# 두더지잡기
1. LED
- 파란색 계열 ON(3초): 생명
- 주황색 계열 ON(3초): 두더지
- default: LED OFF

즉, 생명LED를 터치하면 생명 추가, 두더지 LED를 터치하면 점수 추가, 두더지LED를 시간 내에 터치하지 못하면 생명 감소



2. 순서
- 시리얼모니터에서 입력받으면 게임 시작
- 랜덤하게 기다리며, 랜덤으로 LED ON
- 1분동안 진행하고, 시간이 경과되면 게임 stop
- 게임 결과 출력



3. 기술
- 운영체제: Ubuntu 18.04 (Linux)
- 웹서버: PHP + Apache
- 데이터베이스: MySQL
- 와이파이: SWU_WiFi(Free)

즉, 각 큐브의 점수를 ESP8266을 통해 전송. 해당 값들은 실시간으로 DB에 저장되며 타이머 종료 후 웹에 결과를 나타낸다.
주고받을 값: 점수(두더지가 나타났을 때 잡은 경우 카운트함), 전제 시작 및 종료(타이머)

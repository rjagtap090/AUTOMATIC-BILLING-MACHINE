#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

ESP8266WebServer server(80);

const char* ssid = "admin";
const char* password = "12345678";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Wire.begin(D2, D1);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");
  lcd.setCursor(0, 1);
  lcd.print("SMART CART");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.setCursor(0, 0);
    lcd.print("WiFi connecting...");
  }
  lcd.setCursor(0, 0);
  lcd.print("WiFi connected");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(1500);

  server.on("/", []() {
    String page = "<html><head><title>E Cart using IoT</title></head>";
    page += "<body><center><h1>Smart Shopping Cart using IoT</h1><br><br>";
    page += "<table style=\"width: 1200px; height: 450px;\"><tr>";
    page += "<th>ITEMS</th><th>QUANTITY</th><th>COST</th></tr><tr><td>Biscuit</td><td>1</td><td>35.00</td></tr>";
    page += "<tr><td>Soap</td><td>1</td><td>38.00</td></tr><tr><td>Rice(1KG)</td><td>1</td><td>55.00</td></tr>";
    page += "<tr><td>Tea(50g)</td><td>1</td><td>45.00</td></tr>";
    page += "<tr><th>Grand Total</th><th>4</th><th>173.00</th></tr></table>";
    page += "<br><input type=\"button\" name=\"Pay Now\" value=\"Pay Now\" style=\"width: 200px; height: 50px\"></center></body></html>";
    page += "<meta http-equiv=\"refresh\" content=\"2\">";
    server.send(200, "text/html", page);
  });

  server.begin();
}

void loop() {
  server.handleClient();
  int a = digitalRead(D3);

  char input[12];
  int count = 0;
  while (Serial.available() && count < 12) {
    input[count] = Serial.read();
    count++;
    delay(5);
  }

  if ((strncmp(input, "0B00291F5B66", 12) == 0) && (a == 1)) {
    lcd.setCursor(0, 0);
    lcd.print("Biscuit Added");
    lcd.setCursor(0, 1);
    lcd.print("Price(Rs):35.00");
    digitalWrite(D4, HIGH);
    delay(2000);
    digitalWrite(D4, LOW);
    lcd.clear();
  } else if ((strncmp(input, "0B00291F5B66", 12) == 0) && (a == 0)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Biscuit Removed!!!");
    digitalWrite(D4, HIGH);
    delay(2000);
    digitalWrite(D4, LOW);
    lcd.clear();
  }

  server.handleClient();
}

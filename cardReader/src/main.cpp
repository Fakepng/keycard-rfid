#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SPI.h>
#include <MFRC522.h>

int SS_PIN = D2;
int RST_PIN = D1;

const char* ssid = "Fakepng_Iot";
const char* password = "12345678";

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void printHex(byte *buffer, byte bufferSize);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    Serial.println();
  }

  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  Serial.print(F("Card UID:"));
  printHex(rfid.uid.uidByte, rfid.uid.size);
  Serial.println();

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
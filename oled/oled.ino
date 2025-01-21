#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Replace with your network credentials
#define ssid  ""
#define password ""


// Initialize Telegram BOT
#define BOTtoken ""  // your Bot Token (Get from Botfather)
#define CHAT_ID ""    // get from ID Bot

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int pirsensor = 27;
bool motionDetected = false;

void IRAM_ATTR detectsMotion() {
  motionDetected = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(pirsensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pirsensor), detectsMotion, RISING);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "Device Activated and initiating the process.", "");
}

void loop() {
  if(motionDetected){
    bot.sendMessage(CHAT_ID, "Motion Detected!", "");
    Serial.println("Motion Detected!");
    motionDetected = false;
  }
}
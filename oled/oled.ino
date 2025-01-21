#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Replace with your network credentials
#define ssid  "PRAJWAL_111"
#define password "12345678"


// Initialize Telegram BOT
#define BOTtoken "7096397057:AAF9yWdlXbux6pTZGN_lNFe_Bvy_adpcte0"  // your Bot Token (Get from Botfather)
#define CHAT_ID "2064900742"    // get from ID Bot

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
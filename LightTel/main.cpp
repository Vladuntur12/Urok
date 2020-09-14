#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientsecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "Boteon MikroTik";
const char* password = "Boteon12345";

const char* BotToken = "1321141043:AAGXkYiXRgaKD_0-RAsMu1iC3OTCE5NRO8Q";

WiFiClientSecure net_ssl;
UniversalTelegramBot bot(BotToken, net_ssl);

void setup() {
 Serial.begin(115200);
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED)
 {
   delay(1000);
   Serial.print(".");
 }
 Serial.println("Connected");
 pinMode(19, OUTPUT);
}

void loop() 
{
  if(bot.getUpdates(bot.last_message_received + 1))
  {
   String chat_id= String(bot.messages[0].chat_id);
   String text = bot.messages[0].text;
   if(text == "ON")
  {
    digitalWrite(19,HIGH);
    bot.sendMessage(chat_id, "socket is U");
  } 
  else if (text == "OFF")
  {
    digitalWrite(19,LOW);
    bot.sendMessage(chat_id, "NO, ON");
  }
  
}
  

}
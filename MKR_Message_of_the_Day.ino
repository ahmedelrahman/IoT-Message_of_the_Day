#include <SPI.h> //you don't need this as we arn't using the shiled just chip
#include <WiFi101.h>
#include <LiquidCrystal.h>
#include <TelegramBot.h>

char ssid[] = "BHNTC8715D5D54"; //  your network SSID (name)
char pass[] = "349554a8";    //your network password
int keyIndex = 0;     // your network key Index number (needed only for WEP)   ???

const int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const char* BotToken = "802957527:AAEvPzceweJgz0a2rslAUkoJnNoQRMgYEy0";    // your Bot Teken  

WiFiSSLClient client;

TelegramBot bot(BotToken,client);
const char *botText;
int temp = 0;
void setup() 
{  
 Serial.begin(115200);  
 while (!Serial) {}  //Start running when the serial is open 
 delay(3000);  
 // attempt to connect to Wifi network:  
 Serial.print("Connecting Wifi: ");  
 Serial.println(ssid);  
 while (WiFi.begin(ssid, pass) != WL_CONNECTED) 
       {  
   Serial.print(".");  
   delay(500);  
 }  
 Serial.println("");  
 Serial.println("WiFi connected");  
 bot.begin();  
 
 lcd.begin(16, 2);
}

void loop() 
{  

const char* botsender;
String b; 

message m = bot.getUpdates(); // Read new messages  

if(strcmp(botText,m.text.c_str()) != 0 || temp == 0)
{
lcd.setCursor(0, 1);
lcd.print("                ");
}

botText = m.text.c_str();


lcd.setCursor(0, 0);
lcd.print("MOTD           ");

lcd.setCursor(0, 1);
lcd.print(botText);

Serial.println("message received");  
bot.sendMessage(m.chat_id, m.text + " will be displayed");  

botsender = m.sender.c_str();

Serial.println(botsender);

//delay(2000);

Serial.println(botText);

temp++;

}

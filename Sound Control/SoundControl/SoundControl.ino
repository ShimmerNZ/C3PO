#include <esp_now.h>
#include <WiFi.h>
#include <DFRobotDFPlayerMini.h>
#include <FastLED.h>

#define CHANNEL 1
#define LED_PIN     12
#define NUM_LEDS    50
#define BRIGHTNESS  96
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

enum Effect {LIGHTSABER_GLOW, HYPERSPACE_JUMP, DROID_SPEAK, GALAXY_TWINKLE, REACTOR_CORE, TIE_FIGHTER_DASH, HOLOGRAM_PROJECTION, KYBER_CRYSTAL_CHARGE, BATTLE_DAMAGE_FLICKER, FORCE_PRESENCE};
Effect currentEffect;
unsigned long previousMillis = 0;
unsigned long interval = 500; // Initial interval

// Initialize DFPlayer Mini
DFRobotDFPlayerMini myDFPlayer;

// Init ESP Now with fallback
void InitESPNow() {
  WiFi.disconnect();
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESPNow Init Success");
  }
  else {
    Serial.println("ESPNow Init Failed");
    // Retry InitESPNow, add a counte and then restart?
    // InitESPNow();
    // or Simply Restart
    ESP.restart();
  }
}

// config AP SSID
void configDeviceAP() {
  String Prefix = "Slave:";
  String Mac = WiFi.macAddress();
  String SSID = Prefix + Mac;
  String Password = "123456789";
  bool result = WiFi.softAP(SSID.c_str(), Password.c_str(), CHANNEL, 0);
  if (!result) {
    Serial.println("AP Config failed.");
  } else {
    Serial.println("AP Config Success. Broadcasting with AP: " + String(SSID));
  }
}

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print("Last Packet Recv from: "); Serial.println(macStr);
  currentEffect = static_cast<Effect>(random(0, 10));
  myDFPlayer.play(1);

}

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    Serial2.begin(9600, SERIAL_8N1, 16, 17);  // RX = GPIO16, TX = GPIO17

    // Initialize DFPlayer Mini
    if (!myDFPlayer.begin(Serial2)) {  // Use hardware Serial2 to communicate with the DFPlayer Mini
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
        while (true);
    }
    Serial.println(F("DFPlayer Mini online."));

    myDFPlayer.volume(25);  // Set volume value (0-30)

  Serial.println("ESPNow - Slave");
  WiFi.mode(WIFI_AP);
  configDeviceAP();
  Serial.print("AP MAC: "); Serial.println(WiFi.softAPmacAddress());
  InitESPNow();
  esp_now_register_recv_cb(OnDataRecv);

  // LED Setup
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  currentEffect = static_cast<Effect>(random(0, 10));
}

void loop() {
    switch (currentEffect) {
    case LIGHTSABER_GLOW:
      lightSaberGlow();
      break;
    case HYPERSPACE_JUMP:
      hyperspaceJump();
      break;
    case DROID_SPEAK:
      droidSpeak();
      break;
    case GALAXY_TWINKLE:
      galaxyTwinkle();
      break;
    case REACTOR_CORE:
      reactorCore();
      break;
    case TIE_FIGHTER_DASH:
      tieFighterDash();
      break;
    case HOLOGRAM_PROJECTION:
      hologramProjection();
      break;
    case KYBER_CRYSTAL_CHARGE:
      kyberCrystalCharge();
      break;
    case BATTLE_DAMAGE_FLICKER:
      battleDamageFlicker();
      break;
    case FORCE_PRESENCE:
      forcePresence();
      break;
  }
  FastLED.show();
}

CRGB getRandomColor() {
  return CRGB(random(0, 256), random(0, 256), random(0, 256));
}

void lightSaberGlow() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    fill_solid(leds, NUM_LEDS, getRandomColor());
    FastLED.show();
    interval = 500;
  }
}

// Continue for other effects using millis() and getRandomColor()

void hyperspaceJump() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
    }
    FastLED.show();
    interval = 50;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
      FastLED.show();
    }
    interval = 50;
  }
}

void droidSpeak() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = getRandomColor();
    }
    FastLED.show();
    interval = 100;
    FastLED.clear();
  }
}

// Continue for other effects...

void galaxyTwinkle() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    for (int i = 0; i < NUM_LEDS / 2; i++) {
      leds[random(NUM_LEDS)] = CRGB::White;
    }
    FastLED.show();
    interval = 500;
    FastLED.clear();
  }
}

void reactorCore() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    fill_solid(leds, NUM_LEDS, CRGB::Orange);
    FastLED.show();
    interval = 500;
    fill_solid(leds, NUM_LEDS, CRGB::White);
    FastLED.show();
  }
}

// Other functions follow the same structure.

void tieFighterDash() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
      FastLED.show();
      interval = 50;
      leds[i] = CRGB::Black;
    }
  }
}

void hologramProjection() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    fill_solid(leds, NUM_LEDS, CRGB::LightBlue);
    FastLED.show();
    interval = 100;
    fill_solid(leds, NUM_LEDS, CRGB::DarkBlue);
    FastLED.show();
  }
}

void kyberCrystalCharge() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
      FastLED.show();
      interval = 100;
    }
  }
}

void battleDamageFlicker() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
      FastLED.show();
      interval = 50;
      leds[i] = CRGB::Black;
      FastLED.show();
      interval = 50;
    }
  }
}

void forcePresence() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
      FastLED.show();
      interval = 1000;
      leds[i] = CRGB::Green;
      FastLED.show();
      interval = 1000;
    }
  }
}
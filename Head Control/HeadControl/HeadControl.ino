#include <esp_now.h>
#include <WiFi.h>
#include <FastLED.h>

#define CHANNEL 1
#define LED_PIN     13
#define NUM_LEDS    6
#define BRIGHTNESS  120
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

unsigned long previousMillis = 0;
unsigned long effectStartMillis = 0;
unsigned long interval = 10000; // 10 seconds
unsigned long effectDuration = 5 * 60 * 1000; // 5 minutes
int currentEffect = 0;
bool effectChanged = false;

// Init ESP Now with fallback
void InitESPNow() {
  WiFi.disconnect();
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESPNow Init Success");
  } else {
    Serial.println("ESPNow Init Failed");
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

  int randValue = random(0, 10);
  if (randValue < 6) {  // 60% chance
    currentEffect = (randValue % 3 == 0) ? 0 : (randValue % 3 == 1) ? 3 : 4;
  } else {  // 40% chance
    currentEffect = random(1, 6);
    if (currentEffect == 0 || currentEffect == 3 || currentEffect == 4) {
      currentEffect = 6; // Ensure the case doesn't overlap with 0, 3, 4
    }
  }

  effectStartMillis = millis();  // Record the time the effect was changed
  effectChanged = 
  Serial.print(currentEffect);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("ESPNow - Slave");
  WiFi.mode(WIFI_AP);
  configDeviceAP();
  Serial.print("AP MAC: "); Serial.println(WiFi.softAPmacAddress());
  InitESPNow();
  esp_now_register_recv_cb(OnDataRecv);

  // LED Setup
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  unsigned long currentMillis = millis();

  if (effectChanged && (currentMillis - effectStartMillis >= effectDuration)) {
    currentEffect = 0;  // Switch back to case 0 after 5 minutes
    effectChanged = false;
  }

  switch (currentEffect) {
    case 0: solidColor(CRGB::Orange); break;
    case 1: solidColor(CRGB::Blue); break;
    case 2: solidColor(CRGB::Red); break;
    case 3: solidColor(CRGB(255, 223, 196)); break; // Warm White
    case 4: sparkle(CRGB::Orange); break;
    case 5: rapidPulseB(CRGB::Blue); break;
    case 6: rapidPulseR(CRGB::Red); break;
  }

  FastLED.show();
}

void solidColor(CRGB color) {
  fill_solid(leds, NUM_LEDS, color);
}

void sparkle(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (random(10) < 3) ? color : CRGB::Black; // 30% chance to sparkle
  }
  delay(100);
}

void rapidPulseB(CRGB color) {
 for (int brightness = 0; brightness <= 255; brightness++) {
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, brightness)); // Blue
    FastLED.show();
    delay(5);
  }
   for (int brightness = 255; brightness >= 0; brightness--) {
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, brightness)); // Blue
    FastLED.show();
    delay(5);
   }
}

void rapidPulseR(CRGB color) {
 for (int brightness = 0; brightness <= 255; brightness++) {
    fill_solid(leds, NUM_LEDS, CRGB(brightness,0,0)); // Blue
    FastLED.show();
    delay(5);
  }
   for (int brightness = 255; brightness >= 0; brightness--) {
    fill_solid(leds, NUM_LEDS, CRGB(brightness,0,0)); // Blue
    FastLED.show();
    delay(5);
   }
}
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        14 // On Trinket or Gemma, suggest changing this to 1



// LED config

const int brights[]  {1, 8, 32, 64, 128, 184, 255};
const int colors[7][3]   {{255, 255, 255}, {255, 0, 255}, {0, 255, 255}, {255, 255, 0}, {0, 0, 255}, {255, 0, 0}, {0, 255, 0}};
// board things that change
int bright = 0;
// Color of your personal LED
int myColor = 1;


// person config
int myLed = 1;

// 
int subList[] = {-1,0,1,2,3,4,5,6,7,8,9,10};

int ledValues[sizeof(subList)][3];
int i = 0;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS sizeof(subList) // Popular NeoPixel ring size


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define brightButon 12
#define colorButton 13
#define smileyButton 15
int currentRecipient = -1;

int tempTimer = 0;

bool pressedButtons[] = {false, false, false};
void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(15, INPUT);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {

  updateAll();
  handlePress(getButtonPresses());
  
  pixels.show();   // Send the updated pixel colors to the hardware.
  
  // visual test
  for (int j = 0; j < NUMPIXELS-1; j++) {
    if (millis()>tempTimer){
    personMap[random(NUMPIXELS-1)] = ;
    tempTimer = millis() + random(200)
    }
  }
}

void handlePress(int bttn){
  switch(bttn){
    case 0: 
      break;
     case 12:
      serial.print("btn12");
      break;
     case 13:
      serial.print("btn12");
      break;
     case 15:
      serial.print("btn12");
      break;
  }
  
}

int getButtonPresses(){
  return 0 
}

void handleDM(){
  
}
void handleTimeChange(){
  
}

void changeColor() {
  myColor ++;
  myColor = myColor % sizeof(colors);

}

void changeBrightness() {
  bright ++;
  bright = bright % sizeof(brights);
}


void updatePx(int i, int pixar[3]) {
  pixels.setPixelColor(i, pixar[0] * brights[bright] / 255, pixar[1] * brights[bright] / 255 , pixar[2]* brights[bright] / 255 );
}

void updateAll() {
  pixels.clear();
  for (int i = 0; i < sizeof(subList); i++) {
    updatePx(i, subList(i));
  }
  pixels.show();
}

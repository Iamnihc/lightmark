// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        14 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int brightness =  1;
#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

void setup() {
  
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {


  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
        pixels.setPixelColor((i+5)%NUMPIXELS, pixels.Color(255 * brightness / 100 , 0 * brightness / 100, 0 * brightness / 100));
    pixels.setPixelColor((i+4)%NUMPIXELS, pixels.Color(255 * brightness / 100, 255 * brightness / 100, 0 * brightness / 100));
    pixels.setPixelColor((i+3)%NUMPIXELS, pixels.Color(0 * brightness / 100, 255 * brightness / 100, 0 * brightness / 100));
    pixels.setPixelColor((i+2)%NUMPIXELS, pixels.Color(0 * brightness / 100, 255 * brightness / 100, 255 * brightness / 100));
    pixels.setPixelColor((i+1)%NUMPIXELS, pixels.Color(0 * brightness / 100, 0 * brightness / 100, 255 * brightness / 100));
    pixels.setPixelColor(i, pixels.Color(255 * brightness / 100,0 * brightness / 100,255 * brightness / 100));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}

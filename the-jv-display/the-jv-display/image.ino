/*
  code is generated by jvsmg-tool (jv state machine generator)',
  file 'image' generated on 2023-05-09 19:41:15
*/

// Module image
#include <FastLED.h>

// settings

// Number of leds in matrix
#ifndef IMAGE_NUM_LEDS
#define IMAGE_NUM_LEDS (16 * 16)
#endif

// Data pin of led matrix
#ifndef IMAGE_DATA_PIN
#define IMAGE_DATA_PIN 3
#endif

// RGB order of RGB leds (for WS2812B default GRB)
#ifndef IMAGE_RGB_ORDER
#define IMAGE_RGB_ORDER GRB
#endif

const byte PIXEL_SIZE = 3;

// Brightness (do not make it to bright, otherwise the led matrix can be damaged)
const uint8_t imageBrightness{10};

// the leds
unsigned int imageCurrentIndex{0};
CRGB imageLeds[IMAGE_NUM_LEDS];

// --- Setup -----------

void imageSetup()
{
  FastLED.addLeds<WS2812B, IMAGE_DATA_PIN, IMAGE_RGB_ORDER>(imageLeds, IMAGE_NUM_LEDS);
}

// --- Commands -----------
void imageStartLoad()
{
  imageCurrentIndex = 0;
}

bool imageIsLoaded()
{
  return imageCurrentIndex > 255;
}

bool imageIsPixelAvailableOnSerial()
{
  return Serial.available() >= PIXEL_SIZE;
}

void imageLoad()
{
  while (imageIsPixelAvailableOnSerial() && (imageCurrentIndex < IMAGE_NUM_LEDS))
  {
    CRGB &pixel = imageLeds[imageCurrentIndex];
    Serial.readBytes(pixel.raw, PIXEL_SIZE); // ignore return value
    ++imageCurrentIndex;
  }
}

void imageLoadDefault()
{
  // TODO: implement command 'loadDefault'
  for (auto &led : imageLeds)
  {
    led = CRGB::SteelBlue;
  }
}

void imageShow()
{
  FastLED.show(imageBrightness);
}

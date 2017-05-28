// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

int iLoopLog = 0;
int iR=0;
int iG =0;
int iB =0;
int iBright = 50;
void setup() {
    Serial.begin(9600);
  Serial.println("START");
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  iLoopLog = Serial.read();
  
  if (iLoopLog == '1')
  {
    Serial.println("1 (R)");
    iR+=10;
  }
  else if ( iLoopLog == '2')
  {
    Serial.println("2 (G)");
    iG+=10;
  }
  else if ( iLoopLog == '3')
  {
    Serial.println("3 (B)");
    iB+=10;
  }
  else if (iLoopLog == '4')
  {
    Serial.println("1 - (R)");
    iR-=10;
  }
  else if ( iLoopLog == '5')
  {
    Serial.println("2- (G)");
    iG-=10;
  }
  else if ( iLoopLog == '6')
  {
    Serial.println("3- (B)");
    iB-=10;
  }
  else if ( iLoopLog == '8')
  {
    Serial.println("iBright +");
    iBright+=10;
  }
  else if ( iLoopLog == '9')
  {
    Serial.println("iBright -");
    iBright-=10;
  }


    Serial.print("Color :");
    Serial.print(" R(");
    Serial.print(iR,DEC);
    Serial.print(") G(");
    Serial.print(iG,DEC);
    Serial.print(") B(");
    Serial.print(iB,DEC);
    Serial.print(") BRIGHTNESS = ");
    Serial.println(iBright,DEC);

  
  for(int i=0;i<NUMPIXELS;i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(iR,iG,iB)); // Moderately bright green color.
    pixels.setBrightness(iBright);
  }
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(10);
    
}

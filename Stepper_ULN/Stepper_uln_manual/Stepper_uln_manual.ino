#include <Stepper.h>

#define DEBUG true

//Definicja portow
#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5

/*
 * Klasa Motor
 * Do zarzadzania działaniem silnika krokowego
 */
class Motor {
  public:
  int m_iStep;
  private:
  int state;
  int coil[4];
  int cs[4];

  public:
  Motor(int coil1, int coil2, int coil3, int coil4)
  {
    #if DEBUG
    Serial.begin(9600);
    Serial.println("Motor::Motor : ");
    #endif

    //ponfiguracja portow jako wyjscia
    pinMode(coil1, OUTPUT);
    pinMode(coil2, OUTPUT);
    pinMode(coil3, OUTPUT);
    pinMode(coil4, OUTPUT);
    
    //przypisanie tablicy obwodow silnika
    coil[0] = coil1;
    coil[1] = coil2;
    coil[2] = coil3;
    coil[3] = coil4;

    //konfiguracja cyklu zwojów silnika - kolejnosc przekazywanych wartosci
    cs[0] = 10;//1010
    cs[1] = 6;//0110
    cs[2] = 5;//0101
    cs[3] = 9;//1001
    
    m_iStep =0;
    state=0;
  }

  //obrot silnika domyslnie 2048 krokow to pelny obrot 
  //Stride Angle = 5,625deg/64
  void rotate(int count = 2048) //2048 -> 360degree
  {
    Logln("Motor::rotate : ");
    for(int i =0; i<count; i++){
      setCoilsLevel();
      delay(20);
    }
    
  }
  private:
  void setCoilsLevel()
  {
    
    
    //Log("Motor::step : ");
    //Log(cs[state], BIN);
    //Log(" ");
    for(int i=0;i<4;i++)
    {
      if( cs[state] & 1<<i ){
        digitalWrite(coil[i],HIGH);
        //Log(coil[i], DEC);
        //Log("H ");
      }
      else{
        digitalWrite(coil[i], LOW); 
        //Log(coil[i], DEC);
        //Log("L ");
      }
    }
    //Logln("");
    state++;
    if(state >= 4) state=0;
  }

  //ToDo : own log function. Replace Serial.print and Serial.println
    size_t Log(const __FlashStringHelper *c){Serial.print(c);}
    size_t Log(const String &c){Serial.print(c);}
    size_t Log(const char * c){Serial.print(c);}
    size_t Log(char c){Serial.print(c);}
    size_t Log(unsigned char c , int x= DEC){Serial.println(c,x);}
    size_t Log(int c, int x= DEC){Serial.println(c,x);}
    size_t Log(unsigned int c, int x= DEC){Serial.println(c,x);}
    size_t Log(long c, int x= DEC){Serial.println(c,x);}
    size_t Log(unsigned long c, int x= DEC){Serial.println(c,x);}
    size_t Log(double c, int x= 2){Serial.println(c,x);}

    size_t Logln(const __FlashStringHelper *c){Serial.print(c);}
    size_t Logln(const String &c){Serial.print(c);}
    size_t Logln(const char *c){Serial.print(c);}
    size_t Logln(char c){Serial.print(c);}
    size_t Logln(unsigned char c, int x= DEC){Serial.println(c,x);}
    size_t Logln(int c, int x= DEC){Serial.println(c,x);}
    size_t Logln(unsigned int c, int x= DEC){Serial.println(c,x);}
    size_t Logln(long c, int x= DEC){Serial.println(c,x);}
    size_t Logln(unsigned long c, int x= DEC){Serial.println(c,x);}
    size_t Logln(double c, int x= 2){Serial.println(c,x);}
    size_t Logln(const Printable& c){Serial.print(c);}

};

const int stepsPerRevol = 200;
int inByte = 0;
int iLoopLog = 0;
int motorSpeed = 0;
int motorStep = 1000;

Motor motor( IN1, IN2, IN3, IN4);
int stepCount = 0;

int LoopCounter =0;

void setup() {
  Serial.begin(9600);
  Serial.println("START");

}

void loop() {
  LoopCounter ++;
  //delay(100);
  //iLoopLog = Serial.read();
  //Serial.print("Loop ");
  //Serial.println(iLoopLog, DEC);
  Serial.println(LoopCounter);
  motor.rotate(2048);
  delay(5000);
  
  
  

}

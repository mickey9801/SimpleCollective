#include <Joystick.h>

Joystick_ Joystick;

// put the max and min values from the analogRead in these arrays
// these are translated to a range of 0 - 1023
int axisLimits0[] = {0, 1023};

// setting mode prints the pin value and translated value to the serial monitor
bool printVals = false;

void setup() {
  Joystick.begin();
  if(printVals) Serial.begin(9600);
}

void loop() {
  int value = 0;
  int pos = 0;

  value = analogRead(A2);
  pos = translateValue(value, axisLimits0[0], axisLimits0[1]);
  Joystick.setThrottle(pos);
  if(printVals) settingPrint(value, pos);
  
  delay(5);
}

int translateValue(int v, int f1, int f2){
  // translates values to a 0 - 1023 range
  /*
  int result = 0;
  int start = 0;
  float range = 0;
  
  if(f1 < f2){
    start = f1;
    range = f2 - f1;
  }
  else{
    start = f2;
    range = f1 - f2;
  }
  
  result = (v - start) * (1023 / range);
  //*/
  int result = map(v, f1, f2, 0, 1023);
  if(result < 0) result = 0;
  if(result > 1023) result = 1023;
  
  return result;
}

void settingPrint(int value, int pos){
  Serial.print(value); 
  Serial.print(" "); 
  Serial.println(pos);
}

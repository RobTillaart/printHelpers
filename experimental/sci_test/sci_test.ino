//
//    FILE: sci_test.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test different values with sci function


#include "Arduino.h"
#include "printHelpers.h"

uint32_t start, stop;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.println();

  //  Serial.println(sci(PI, 8));
  //  Serial.println(scientific(PI, 8));

  //  Serial.println(sci(0, 8));
  //  Serial.println(scientific(0, 8));
  //  Serial.println(sci(PI, 8));
  //  Serial.println(scientific(PI, 8));
  //  Serial.println(sci(-PI, 8));
  //  Serial.println(scientific(-PI, 8));
  //  Serial.println(sci(pow(PI, 75), 8));
  //  Serial.println(scientific(pow(PI, 75), 8));
  //  delay(100);
  //
  //  Serial.println();
  //  uint32_t start = micros();
  //  char * p = sci(1E37, 8);
  //  uint32_t stop = micros();
  //  Serial.print(stop - start);
  //  Serial.print("\t");
  //  Serial.println(p);
  //  delay(100);
  //
  //  start = micros();
  //  p = scientific(1E37, 8);
  //  stop = micros();
  //  Serial.print(stop - start);
  //  Serial.print("\t");
  //  Serial.println(p);
  //
  //  Serial.println();
  //  start = micros();
  //  p = sci(-1E-35, 8);
  //  stop = micros();
  //  Serial.print(stop - start);
  //  Serial.print("\t");
  //  Serial.println(p);
  //  delay(100);
  //
  //  start = micros();
  //  p = scientific(-1E-35, 8);
  //  stop = micros();
  //  Serial.print(stop - start);
  //  Serial.print("\t");
  //  Serial.println(p);
  //
  //
  //  Serial.println();
  //  start = micros();
  //  p = sci(12345, 8);
  //  stop = micros();
  //  Serial.print(stop - start);
  //  Serial.print("\t");
  //  Serial.println(p);
  //  delay(100);
  //
  //  start = micros();
  //  p = scientific(12345, 8);
  //  stop = micros();
  //  Serial.print(stop - start);
  //  Serial.print("\t");
  //  Serial.println(p);

  Serial.println("\nDone...");
}


void loop()
{
}


//  uses log10 and pow
char * scientific(double value, uint8_t decimals)
{
  static char buffer[20];
  uint8_t pos = 0;
  if (isnan(value))
  {
    strcpy(buffer, "nan");
    return buffer;
  }
  if (isinf(value))
  {
    if (value < 0) strcpy(buffer, "-inf");
    strcpy(buffer, "inf");
    return buffer;
  }
  if (value == 0)
  {
    buffer[pos++] = '0';
    buffer[pos++] = '.';
    while (decimals-- > 0) buffer[pos++] = '0';
    sprintf(&buffer[pos], "E%+d", 0);
    return buffer;
  }
  bool neg = (value < 0);
  if (neg)
  {
    value = -value;
    buffer[pos++] = '-';
  }
  int pwr = log10(value);
  value *= pow(10, -pwr);
  buffer[pos++] = '0' + int(value);
  buffer[pos++] = '.';
  int t = int(value);
  while (decimals--)
  {
    value -= t;
    value *= 10;
    t = int(value);
    buffer[pos++] = '0' + t;
  }
  sprintf(&buffer[pos], "E%+d", pwr);
  return buffer;
}


//  -- END OF FILE --

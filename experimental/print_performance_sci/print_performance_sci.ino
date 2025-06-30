//
//    FILE: print_performance_sci.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo program SCI
//     URL: https://github.com/RobTillaart/printHelpers


#include "sci.h"


uint32_t start = 0;
uint32_t stop = 0;
char * b;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.println();

  Serial.println(sizeof(float));
  Serial.println(sizeof(double));


  double c = 2.99792458E8;   //  speed of light;
  double m = 7.34767309E20;  //  mass of moon
  double E = m * c * c;

  Serial.println();
  Serial.println("     Mass moon M = 7.34767309E+20");
  Serial.println("Speed of light c = 2.99792458E+8");
  Serial.println("         Print E = Mc^2 = 6.6037592413026551656653076E+37 \n");
  Serial.println();

  E = 660375924130265516;

  Serial.println();
  Serial.println("SCI");
  delay(100);
  start = micros();
  for (int len = 0; len < 16; len++)
  {
    b = sci(E, len);
  }
  stop = micros();
  Serial.print("TIME: ");
  Serial.println(stop - start);
  Serial.println(b);

  Serial.println();
  Serial.println("ENG");
  delay(100);
  start = micros();
  for (int len = 0; len < 16; len++)
  {
    b = eng(E, len);
  }
  stop = micros();
  Serial.print("TIME: ");
  Serial.println(stop - start);
  Serial.println(b);


  Serial.println();
  Serial.println("done...");
}


void loop()
{
}


//  -- END OF FILE --

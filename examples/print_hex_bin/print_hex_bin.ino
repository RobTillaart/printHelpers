//
//    FILE: print_hex_bin.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo hex(value, sep);


#include "printHelpers.h"

volatile uint32_t n = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);

  Serial.println();
  Serial.println("10 random() HEX values");
  for (uint8_t i = 0; i < 10; i++)
  {
    n = 2 * random() + random(2);  //  0 .. 2^32-1
    Serial.print(n);
    Serial.print('\t');
    Serial.print(hex(n));
    Serial.print('\t');
    Serial.println(n, HEX);
  }
  Serial.println();

  Serial.println("10 random() BIN values");
  for (uint8_t i = 0; i < 10; i++)
  {
    n = 2 * random() + random(2);  //  0 .. 2^32-1
    Serial.print(n);
    Serial.print('\t');
    Serial.print(bin(n));
    Serial.print('\t');
    Serial.println(n, BIN);
  }
  Serial.println();

  Serial.println("\ndone...");
}


void loop()
{
}


// -- END OF FILE --

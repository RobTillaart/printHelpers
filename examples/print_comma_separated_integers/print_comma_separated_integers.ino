//    FILE: print_comma_separated_integers.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2023-12-20
// PURPOSE: readability
//     URL: https://github.com/RobTillaart/printHelpers

#include "Arduino.h"
#include "printHelpers.h"

uint32_t start, stop;

void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println(__FILE__);
  Serial.print("PRINTHELPERS_VERSION: ");
  Serial.println(PRINTHELPERS_VERSION);

  Serial.println(123456789);
  Serial.println(csi(123456789));
  Serial.println(csi(-123456789));
  Serial.println(csi(12345678));
  Serial.println(csi(1234567));
  Serial.println(csi(-12345));
  Serial.println(csi(1234));
  Serial.println(csi(123));
  Serial.println(csi(12));
  Serial.println(csi(-1));

  int64_t big = 123456789012345678;
  Serial.println(csi(big));
}

void loop()
{
  uint64_t large = 0;
  for (int i = 0; i < 64; i++)
  {
    large += random(2);
    large *= 2;
  }
}

// -- END OF FILE --

//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-06
// PURPOSE: unit tests for the printHelpers
//          https://github.com/RobTillaart/printHelpers
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "printHelpers.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_sci_eng)
{
  fprintf(stderr, "VERSION: %s\n", PRINTHELPERS_VERSION);
  fprintf(stderr, "PRINTBUFFERSIZE: %d\n", PRINTBUFFERSIZE);

  int32_t value32 = 1 << 25;

  fprintf(stderr, "%ld\n", value32);

  assertEqual(0, strcmp("0", eng(PI * 1000, 6)) );
  assertEqual(0, strcmp("0", sci(PI * 100, 6)) );
  assertEqual(0, strcmp("0", eng(EULER * 10, 6)) );
  assertEqual(0, strcmp("0", sci(EULER * 10000, 6)) );
  
  assertEqual(0, strcmp("0", toBytes(12345678, 3)) );
}


unittest(test_print64)
{
  fprintf(stderr, "PRINTBUFFERSIZE: %s\n", PRINTBUFFERSIZE);

  // int64_t value64 = 1ULL << 35;

  // fprintf(stderr, "%ld\n", value64);
  
  // assertEqual(0, strcmp("0", print64(value64)) );
  // assertEqual(0, strcmp("0", print64(value64, HEX)) );

  // assertEqual(0, strcmp("0", eng(PI * 1000, 6)) );
  // assertEqual(0, strcmp("0", sci(PI * 100, 6)) );
  // assertEqual(0, strcmp("0", eng(EULER * 10, 6)) );
  // assertEqual(0, strcmp("0", sci(EULER * 10000, 6)) );
  
  // assertEqual(0, strcmp("0", toBytes(12345678, 3)) );
}

unittest_main()

// --------

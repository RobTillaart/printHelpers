#pragma once
//
//    FILE: sci.h
//  AUTHOR: Rob Tillaart
//    DATE: 2025-06-30
// VERSION: See printHelpers.h
// PURPOSE: Arduino library to help formatting for printing.
//     URL: https://github.com/RobTillaart/printHelpers

//  class implementation of the scieng(), sci() and eng() functions.
//  These do not share the output buffer and should be thread safe.
//  To be verified.

#include "Arduino.h"
#include "stdlib.h"

class scieng
{
  protected:
    char buffer[25];

  public:
    scieng(double value, uint8_t decimals, uint8_t em = 1)
    {
      int     exponent = 0;
      uint8_t pos = 0;
      double  e1 = 10;     //  exponent step > 1
      double  e2 = 0.1;    //  exponent step < 1

      //  scale to multiples of em.
      for (uint8_t i = 1; i < em; i++)
      {
        e1 *= 10;
        e2 *= 0.1;
      }

      //  Handling these costs 13 bytes RAM
      //  shorten them with N, I, -I ?
      if (isnan(value))
      {
        strcpy(buffer, "nan");
        return;
      }
      if (isinf(value))
      {
        if (value < 0) strcpy(buffer, "-inf");
        strcpy(buffer, "inf");
        return;
      }

      //  Handle negative numbers
      if (value < 0.0)
      {
        buffer[pos++] = '-';
        value = -value;
      }

      //  Scale exponent to multiple of em
      //  TODO: can we remove loop to reduce rounding errors
      while (value >= e1)
      {
        value *= e2;
        exponent += em;
      }
      //  TODO: can we remove loop to reduce rounding errors
      while (value < 1 && value != 0.0)
      {
        value *= e1;
        exponent -= em;
      }

      //  Round correctly so that print(1.999, 2) prints as "2.00"
      double rounding = 0.5;
      //  TODO: can we remove loop to reduce rounding errors?
      //        additional loop that steps per 1000?
      for (uint8_t i = 0; i < decimals; ++i)
      {
        rounding *= 0.1;
      }
      value += rounding;
      if (value >= e1)
      {
        exponent += em;
        value *= e2;
      }

      //  Split whole part and remainder
      uint32_t d = (uint32_t)value;
      double remainder = value - d;


      //  print whole part
#if defined(ESP32)
      //  ESP32 does not support %ld  or ltoa()
      itoa(d, &buffer[pos], 10);
#else
      sprintf(&buffer[pos], "%ld", d);
#endif
      pos = strlen(buffer);


      //  print remainder part
      if (decimals > 0)
      {
        buffer[pos++] = '.';    //  decimal point
      }

      //  Extract decimals from the remainder one at a time
      //  to prevent missing leading zero's
      while (decimals-- > 0)
      {
        remainder *= 10;
        d = (uint8_t)remainder;
        buffer[pos++] = d + '0';
        remainder -= d;
      }

      //  print exponent
      buffer[pos++] = 'E';
      if (exponent < 0)
      {
        buffer[pos++] = '-';
        exponent = -exponent;
      }
      else buffer[pos++] = '+';

      if (exponent < 10) buffer[pos++] = '0';
      itoa(exponent, &buffer[pos], 10);
      return;
    }

    inline operator char *() __attribute__((always_inline)) {
      return buffer;
    }
};


class sci : public scieng
{
  public:
    sci(double value, uint8_t decimals) : scieng(value, decimals, 1)
    {}
};


class eng : public scieng
{
  public:
    eng(double value, uint8_t decimals) : scieng(value, decimals, 3)
    {}
};


//  -- END OF FILE --


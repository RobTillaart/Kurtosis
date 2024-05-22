//
//    FILE: kurtosis_add.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2024-05-21
// PURPOSE: investigate effects of Add(value, times)
//     URL: https://github.com/RobTillaart/Kurtosis


#include "Kurtosis.h"

Kurtosis K;

volatile float x = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("KURTOSIS_LIB_VERSION: ");
  Serial.println(KURTOSIS_LIB_VERSION);
  Serial.println();
  delay(100);

  K.reset();
  uint32_t start = micros();
  //  for (int i = 0; i < 100; i++)
  //  {
  //    K.add(i);
  //  }
  for (int i = 0; i < 3; i++)
  {
    K.add(100.23);
  }
  uint32_t stop = micros();
  Serial.print("TIME 1:\t");
  Serial.println(stop - start);
  K.dump();
  delay(100);


  K.reset();
  start = micros();
  //  for (int i = 0; i < 100; i++)
  //  {
  //    K.add(i);
  //  }
  K.add(100.23, 3);  //  faster from 3..255
  stop = micros();
  Serial.println();
  Serial.print("TIME 2:\t");
  Serial.println(stop - start);
  K.dump();

}


void loop()
{

}


//  -- END OF FILE --

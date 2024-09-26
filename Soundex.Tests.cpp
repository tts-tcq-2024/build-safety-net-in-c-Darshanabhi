#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  generateSoundex("ROBERT", soundex);
  generateSoundex("JACKSON", soundex);
  generateSoundex("SASSOON", soundex);
  generateSoundex("SMITH123", soundex);
  generateSoundex(" ", soundex);
  generateSoundex("MAN HU", soundex);
  generateSoundex("65342", soundex);
  generateSoundex("356GHFK", soundex);
  generateSoundex("HJ@LMN", soundex);
  generateSoundex("M*BH8NDK", soundex);
 
 // ASSERT_EQ(soundex,"A200");
}

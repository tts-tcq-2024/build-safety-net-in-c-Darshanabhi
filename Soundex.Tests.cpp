#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  generateSoundex("HARI", soundex);
  generateSoundex("VINU", soundex);
  generateSoundex("JOY", soundex);
  generateSoundex("HI", soundex);
  generateSoundex("HARSH", soundex);
  generateSoundex("MAN", soundex);
  generateSoundex("WU", soundex);
  generateSoundex("BC", soundex);
  generateSoundex("DASH", soundex);
 
 // ASSERT_EQ(soundex,"A200");
}

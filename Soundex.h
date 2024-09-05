#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static char soundexTable[256];
    static int initialized = 0;
    if (!initialized) {
        for (int i = 0; i < 256; ++i) {
            soundexTable[i] = '0'; 
        }
        for (char c : "AEIOUHWY") {
            soundexTable[(unsigned char)c] = '0';
        }
        for (char c : "BFVP") {
            soundexTable[(unsigned char)c] = '1';
        }
        for (char c : "CGJKQSXZ") {
            soundexTable[(unsigned char)c] = '2';
        }
        for (char c : "DT") {
            soundexTable[(unsigned char)c] = '3';
        }
        soundexTable[(unsigned char)'L'] = '4';
        for (char c : "MN") {
            soundexTable[(unsigned char)c] = '5';
        }
        soundexTable[(unsigned char)'R'] = '6';
        initialized = 1;
    }
    return soundexTable[(unsigned char)toupper(c)];
}

void generateSoundexPattern(int len,int sIndex, const char *name, char *soundex) {
 for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
}

void appendNullCharacter(char *soundex, int sIndex) {
 while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    generateSoundexPattern(len,sIndex,name,soundex);
    appendNullCharacter(soundex, sIndex);
}

#endif // SOUNDEX_H

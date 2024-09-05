#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'H' || c == 'W' || c == 'Y') 
        return '0';
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V')
        return '1';
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') 
        return '2';
    if (c == 'D' || c == 'T') 
        return '3';
    if (c == 'L') 
        return '4';
    if (c == 'M' || c == 'N')
        return '5';
    if (c == 'R')
        return '6';
    return '0';  
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

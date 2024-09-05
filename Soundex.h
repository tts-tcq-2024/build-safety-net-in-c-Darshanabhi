#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[256];
    soundexTable['A'] = '0'; soundexTable['E'] = '0'; soundexTable['I'] = '0'; soundexTable['O'] = '0'; soundexTable['U'] = '0';
    soundexTable['H'] = '0'; soundexTable['W'] = '0'; soundexTable['Y'] = '0';
    soundexTable['B'] = '1'; soundexTable['F'] = '1'; soundexTable['P'] = '1'; soundexTable['V'] = '1';
    soundexTable['C'] = '2'; soundexTable['G'] = '2'; soundexTable['J'] = '2'; soundexTable['K'] = '2'; soundexTable['Q'] = '2'; soundexTable['S'] = '2'; soundexTable['X'] = '2'; soundexTable['Z'] = '2';
    soundexTable['D'] = '3'; soundexTable['T'] = '3';
    soundexTable['L'] = '4';
    soundexTable['M'] = '5'; soundexTable['N'] = '5';
    soundexTable['R'] = '6';
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

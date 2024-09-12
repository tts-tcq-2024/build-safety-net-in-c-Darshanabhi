#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

void initializeSoundexTable(char *table) {
    table['A'] = '0'; table['E'] = '0'; table['I'] = '0'; table['O'] = '0'; table['U'] = '0';
    table['H'] = '0'; table['W'] = '0'; table['Y'] = '0';
    table['B'] = '1'; table['F'] = '1'; table['P'] = '1'; table['V'] = '1';
    table['C'] = '2'; table['G'] = '2'; table['J'] = '2'; table['K'] = '2'; table['Q'] = '2'; table['S'] = '2'; table['X'] = '2'; table['Z'] = '2';
    table['D'] = '3'; table['T'] = '3';
    table['L'] = '4';
    table['M'] = '5'; table['N'] = '5';
    table['R'] = '6';
}

char getSoundexCode(char c) {
    static char soundexTable[256];
    initializeSoundexTable(soundexTable);
    return soundexTable[(unsigned char)toupper(c)];
}

void appendCodeToSoundex(char code, char *soundex, int sIndex) {
if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
    }
}

void generateSoundexPattern(int len,int sIndex, const char *name, char *soundex) {
 for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        appendCodeToSoundex(code,soundex,sIndex);
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

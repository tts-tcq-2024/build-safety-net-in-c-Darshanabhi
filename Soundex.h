#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

static const char soundexTable[256] = {
    ['A'] = '0', ['E'] = '0', ['I'] = '0', ['O'] = '0', ['U'] = '0',
    ['H'] = '0', ['W'] = '0', ['Y'] = '0',
    ['B'] = '1', ['F'] = '1', ['P'] = '1', ['V'] = '1',
    ['C'] = '2', ['G'] = '2', ['J'] = '2', ['K'] = '2', ['Q'] = '2', ['S'] = '2', ['X'] = '2', ['Z'] = '2',
    ['D'] = '3', ['T'] = '3',
    ['L'] = '4',
    ['M'] = '5', ['N'] = '5',
    ['R'] = '6'
};

char getSoundexCode(char c) {
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

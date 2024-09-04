#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

void initializeSoundexTable(char *table) {
    memset(table, '0', 256); // Set all to '0'

    // Set specific mappings
    const char* groups[] = {
        "AEIOUHWY", "BFVP", "CGJKQSXZ", "DT", "L", "MN", "R"
    };
    const char codes[] = {'0', '1', '2', '3', '4', '5', '6'};
    
    for (int i = 0; i < sizeof(groups) / sizeof(groups[0]); ++i) {
        for (const char* p = groups[i]; *p; ++p) {
            table[(unsigned char)*p] = codes[i];
        }
    }
}

char getSoundexCode(char c) {
    static char soundexTable[256];
    initializeSoundexTable(soundexTable);
    return soundexTable[(unsigned char)toupper(c)];
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }
    soundex[4] = '\0';
}

#endif // SOUNDEX_H

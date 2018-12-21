/* 
 * Implement an algorithm to determine if a string has all
 * unique characters.
 */

#include <stdio.h>
#include <string.h>

enum {FALSE, TRUE};

int isUnique(char* str) {
    /* 
     * If more than 128 characters, we run out of characters
     * to use. (Assume ASCII)
     */

    int strLength = strlen(str);

    if (strLength > 128) {
        return FALSE;
    }

    int i;
    int char_set[128] = {0};
    for (i = 0; i < strLength; i++) {
        int c = str[i];
        /* Check if we found the character already. */
        if (char_set[c] == TRUE) {
            return 0;
        }
        char_set[c] = 1;
    }

    return TRUE;
}

int main(int argc, char** argv) {
    if (isUnique("Is th")) {
        printf("Is unique.\n");
    }
    else {
        printf("Is not unique.\n");
    }

    return 0;
}

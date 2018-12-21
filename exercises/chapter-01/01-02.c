/*
 * Given two strings, write a method to decide if one
 * is a permutation of the other.
 */

#include <stdio.h>
#include <string.h>

enum {FALSE, TRUE};

int* characterCount(char* str) {
    static int char_count[128] = {0};
    for (int i = 0; i < strlen(str); i++) {
        int c = str[i];
        char_count[c]++;
    }

    return char_count;
}

int checkPermutation(char* str0, char* str1) {
    /* 
     * If string lengths are not the same, they can't be
     * permutations of eachother.
     */
    if (strlen(str0) != strlen(str1)) {
        return FALSE;
    }

    int strLength = strlen(str0);
    int* char_set0 = characterCount(str0);
    int* char_set1 = characterCount(str1);
    
    /*
     * If our character counts are different, the two
     * strings are not permutations. Otherwise, they
     * are.
     */
    for (int i = 0; i < 128; i++) {
        if (char_set0[i] != char_set1[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

int main(int argc, char** argv) {
    char* str0 = "one";
    char* str1 = "neo";

    if (checkPermutation(str0, str1)) {
        printf("Strings permuted.\n");
    }
    else {
        printf("Strings not permuted.\n");
    }

    return 0;
}

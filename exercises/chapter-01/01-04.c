/*
 * Given a string, write a function to check if it is a
 * permutation of a palindrome.
 */

#include <stdio.h>
#include <string.h>

int* characterCount(char* str) {
    static int char_count[128] = {0};
    for (int i = 0; i < strlen(str); i++) {
        int c = str[i];
        char_count[c]++;
    }

    return char_count;
}

int isPermutationOfPalindrome(char* str) {
    int* char_set = characterCount(str);

    /*
     * If string is even length, we simply check all
     * characters appear an even number of times.
     */
    if (strlen(str) % 2 == 0) {
        for (int i = 0; i < 128; i++) {
            if (char_set[i] % 2 != 0) {
                return 0;
            }
        }
        return 1;
    }

    /* 
     * If string is odd length, we need exactly one
     * character that appears an odd number of times.
     */
    else {
        /* Check how many characters appear an odd 
         * number of times.
         */
        int odd_count = 0;
        for (int i = 0; i < 128; i++) {
            if (char_set[i] % 2 != 0) {
                odd_count++;
            }
        }

        if (odd_count == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int main(int argc, char** argv) {
    char* str = "ababccded";

    if (isPermutationOfPalindrome(str) == 1) {
        printf("Is a permutation of a palindrome.\n");
    }
    else {
        printf("Is NOT a permutation of a palindrome.\n");
    }

    return 0;
}

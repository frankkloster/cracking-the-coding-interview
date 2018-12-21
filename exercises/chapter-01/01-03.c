/* 
 * Write a method to replace all spaces in a string with
 * '%20'. You may assume that the string has sufficient
 * space at the end to hold the additional characters.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countSpaces(char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count;
}

char* urlify(char* str) {
    int spaceCount = countSpaces(str);

    // Allocates an extra 2 bytes for every space.
    char* urlifiedStr = malloc((strlen(str) + 2 * spaceCount) * sizeof(char));

    int i = 0; // Counter for original string.
    int j = 0; // Counter for urlified-string.

    for (i = 0; str[i] != EOF; i++) {
        if (str[i] == ' ') {
            urlifiedStr[j] = '%';
            urlifiedStr[j + 1] = '2';
            urlifiedStr[j + 2] = '0';
            j += 3;
        }
        else {
            urlifiedStr[j] = str[i];
            j++;
        }
    }

    return urlifiedStr;
}

int main(int argc, char** argv) {
    char* str = "This is just a test.";
    char* new_str = urlify(str);

    printf("%s\n", new_str);
    free(new_str); // Don't forget to release the memory.

    return 0;
}

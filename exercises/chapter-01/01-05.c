/* There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one
 * (or zero) edits away.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum boolean {FALSE, TRUE};

/*
 * Swaps the entries of two strings.
 * https://www.geeksforgeeks.org/swap-strings-in-c/
 */
void swap(char *str0, char *str1) {
    printf("One swap.");
    char *temp = (char *) malloc((strlen(str0) + 1) * sizeof(char));
    strcpy(temp, str0);
    strcpy(str0, str1);
    strcpy(str1, temp);
    free(temp);
}

/* Swaps strings by swapping pointers */ 
/* void swap(char **str1_ptr, char **str2_ptr) { 
  char *temp = *str1_ptr; 
  *str1_ptr = *str2_ptr; 
  *str2_ptr = temp; 
}  */ 

/* 
 * Checks if one string can be made the other with one replacement
 * character.
 */
int oneEditReplace(char* str0, char* str1) {
    /* 
     * If the strings are different lengths, they cannot be one
     * replacement away.
     */

    if (strlen(str0) != strlen(str1)) {
        return FALSE;
    }
    
    printf("First pass.\n");

    int strLength = strlen(str0);
    int foundDifference = FALSE;
    for (int i = 0; i < strLength; i++) {
        // printf("Next pass...\n");
        if (str0[i] != str1[i]) {
            if (foundDifference == TRUE) {
                return FALSE;
            }
            foundDifference = TRUE;
        }
    }
    
    return TRUE;
}

/*
 * Checks if one string can be made into the other
 * with one removal.
 */
int oneEditInsert(char* str0, char* str1) {
    /* Want str0 to be the bigger string. */
    if (strlen(str0) < strlen(str1)) {
        swap(str0, str1);
    }

    if (strlen(str0) != strlen(str1) + 1) {
        return FALSE;
    }

    printf("One pass.\n");

    int strLength = strlen(str0);

    int index0 = 0, index1 = 0;
    while (index1 < (strLength + 1)  && index0 < strLength) {
        printf("First pass...");
        /* Checks if we hit a different character. */
        if (str0[index0] != str1[index1]) {
            /* Checks if we found a difference before. */
            if (index0 != index1) {
                return FALSE;
            }
            /* Now the indices are one apart. */
            index0++;
        }
        /* No difference found. */
        else {
            index0++;
            index1++;
        }
    }
    return TRUE;
}

int main(int argc, char** argv) {
    printf("One...");
    char* str0 = "abdzd";
    printf("Two...");
    char* str1 = "abdd";

    if (oneEditInsert(str1, str0)) {
        printf("Passed.\n");
    }
    else {
        printf("Did not pass.\n");
    }

    return 0;
}

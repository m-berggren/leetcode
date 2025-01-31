/**
 * Problem: 1768. Merge Strings Alternately
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/merge-strings-alternately?envType=study-plan-v2&envId=leetcode-75
 *
 * Approach:
 * 1. Initially made one while loop with several if-statements and more vaiables
 * 2. Refined it to three separate while loops but operated on copies the strings
 * 3. Lastly, refined to three while loops with operating directly on the strings
 * through pointers.
 *
 * Complexity Analysis:
 * - Time Complexity: O(n + m), through iteration through two different arrays
 * - Space Complexity: O(n + m), constant extra space but still the same
 *
 * Edge Cases:
 * - None
 *
 * Learning:
 * - Working with two pointers
 * - Utilizing logical operators
 * - Malloc & memory allocation
 */


// ------ Include section -----------------------------------------------------
#include <stdio.h>          // for printf
#include <stdlib.h>         // for malloc and free

// ------ Define section ------------------------------------------------------


// ------ Function declarations -----------------------------------------------

// Function that merges two strings by alternating characters
char *merge_alternately(char *w1, char *w2);

// ------ Main ----------------------------------------------------------------
/**
 * Main function that stores two words and then processes them to store
 * alternating characters in an array.
 *
 * Purpose: Demonstrate working with pointers and strings, with some memory
 * allocaiton practise.
 */
int main() {
    // ---- Variable declarations -----
    char *word1 = "hello";
    char *word2 = "world";

    // ---- Program logic -------------

    // Get merged string
    char* merged = merge_alternately(word1, word2);

    // Use merged string
    printf("%s\n", merged);

    // Free memory
    free(merged);

    return 0;
}

// ------ Function definitions ------------------------------------------------
/**
 * Function that merges two words alternately.
 * Note: Memory allocated in this function must be freed by caller
 *
 * @param w1 - Pointer to word1
 * @param w2 - Pointer to word2
 * @return char* array of results (malloc'ed)
 */
char *merge_alternately(char *w1, char *w2){
    // --- Variable declarations ---

    char *result = (char*)malloc(201);  // Allocate max possible size
                                        // (100 + 100 + 1) based on constraints

    char *p1 = w1;                      // Pointer for input strings
    char *p2 = w2;                      // Pointer for input strings

    int k = 0;

    // --- Program logic ---

    while (*p1 && *p2) {
        // Take char from first and second and string and move pointer.
        // k increments after assigning new value to index, ensuring they
        // alternate with word1 being first
        result[k++] = *p1++;
        result[k++] = *p2++;
    }

    // Copy remaining characters from word1, if any
    while (*p1) {
        result[k++] = *p1++;
    }

    // Copy remaining characters from word2, if any
    while (*p2) {
        result[k++] = *p2++;
    }

    // Add null terminator
    result[k] = '\0';

    return result;
}
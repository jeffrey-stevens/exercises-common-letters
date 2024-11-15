/*
    common-letters.c

    Prints out all letters in common between two strings.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


const int NUM_LETTERS = 26;
const uint32_t ALL_LETTERS = (1 << NUM_LETTERS) - 1;


typedef struct {
    uint32_t lower;
    uint32_t upper;
} letter_counts;


void init_counts(letter_counts * counts) {

    // Initialize the letter counts to 0.
    for (int i = 0; i < NUM_LETTERS; ++i) {
        counts->lower = 0;
        counts->upper = 0;
    }
}


void add_letter(letter_counts * counts, char currchar) {

    int idx = 0;

    if (islower(currchar)) {
        idx = currchar - 'a';
        counts->lower |= (1 << idx);
    
    } else if (isupper(currchar)) {
        idx = currchar - 'A';
        counts->upper |= (1 << idx);

    } else {
        // Not a letter; skip
    }
}


void tally_letters(char str[], letter_counts * counts) {

    char currchar;
    bool lower_isfull, upper_isfull;

    init_counts(counts);

    for (int i = 0; (currchar = str[i]) != '\0'; ++i) {
        add_letter(counts, currchar);

        // Break if all letters have been represented
        lower_isfull = !(counts->lower < ALL_LETTERS);
        upper_isfull = !(counts->upper < ALL_LETTERS);

        if (lower_isfull && upper_isfull) {
            break;
        }
    }
}


void compare_letters(letter_counts * counts1, letter_counts * counts2) {

    char outchar;

    uint32_t mask;
    uint32_t common_letters_upper = counts1->upper & counts2->upper;
    uint32_t common_letters_lower = counts1->lower & counts2->lower;
    bool is_common_letter;

    // Uppercase letters
    for (int i = 0; i < NUM_LETTERS; ++i) {

        mask = 1 << i;
        is_common_letter = (common_letters_upper & mask) != 0;
        
        if (is_common_letter) {
            outchar = 'A' + (char) i;
            putchar(outchar);
        }
    }

    // Lowercase letters
    for (int i = 0; i < NUM_LETTERS; ++i) {

        mask = 1 << i;
        is_common_letter = (common_letters_lower & mask) != 0;

        if (is_common_letter) {
            outchar = 'a' + (char) i;
            putchar(outchar);
        }
    }
}


int main(int argc, char * argv[]) {

    char * string1, * string2;
    letter_counts counts1, counts2;

    if (argc < 3) {
        puts("Error:  The program expects 2 argments.");
        exit(1);
    }

    string1 = argv[1];
    string2 = argv[2];

    tally_letters(string1, &counts1);
    tally_letters(string2, &counts2);

    compare_letters(&counts1, &counts2);

    putchar('\n');

    return 0;
}
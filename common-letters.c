/*
    common-letters.c

    Prints out all letters in common between two strings.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


#define NUM_LETTERS 26


typedef struct {
    bool lower[NUM_LETTERS];
    bool upper[NUM_LETTERS];
} letter_counts;


void init_counts(letter_counts * counts) {

    /* Initialize the letter counts to 0. */
    for (int i = 0; i < NUM_LETTERS; ++i) {
        counts->lower[i] = false;
        counts->upper[i] = false;
    }
}


void add_letter(letter_counts * counts, char currchar) {

    int idx = 0;

    if (islower(currchar)) {
        idx = currchar - 'a';
        counts->lower[idx] |= true;
    
    } else if (isupper(currchar)) {
        idx = currchar - 'A';
        counts->upper[idx] |= true;

    } else {
        // Not a letter
    }
}


void tally_letters(char str[], letter_counts * counts) {

    char currchar;

    init_counts(counts);

    for (int i = 0; (currchar = str[i]) != '\0'; ++i) {
        add_letter(counts, currchar);
    }
}


void compare_letters(letter_counts * counts1, letter_counts * counts2) {

    char outchar;

    // Uppercase letters
    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (counts1->upper[i] && counts2->upper[i]) {
            outchar = 'A' + (char) i;
            putchar(outchar);
        }
    }

    // Lowercase letters
    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (counts1->lower[i] && counts2->lower[i]) {
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
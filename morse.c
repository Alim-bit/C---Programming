///////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments >  Information & Policies > Academic Integrity Policy)
///////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// None
//
// Name: Alim Dhuka
// login ID: adhuka
///////////////////////////////////////////////////////////////////////////////

#include "morse.h"
#include <assert.h>
#include <stdbool.h>
#include "cs136-trace.h"

// Your additional includes go here.
#include <stdlib.h>
#include <string.h>
// === THE MORSE ALPHABET =====================================================

// An association of (Latin) letter and Morse sequence
struct morse_code {
    char latin;    // the Latin character
    char morse[6]; // the Morse sequence
};

const int MORSE_ALPHABET_LENGTH = 28;
const struct morse_code MORSE_ALPHABET[28] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-..."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {' ', "P"},     // Represents a long pause
    {'\0', ".-.-."} // Prosign AR: end of transmission
};

// --- THE MORSE ALPHABET: HELPER FUNCTIONS -----------------------------------

// ma_get_morse(letter) returns the Morse sequence associated with the Latin
//   character letter.
// requires: letter must be a Latin letter, space, or the null-terminator
// time:     O(1)
const char *ma_get_morse(char letter) {
    for (int i = 0; i < MORSE_ALPHABET_LENGTH; ++i) {
        if ((MORSE_ALPHABET[i].latin == letter) || (MORSE_ALPHABET[i].latin == letter - 'a' + 'A')) {
            return MORSE_ALPHABET[i].morse;
        }
    }
    assert(false);
}

// comp_str(str1, str2) return true if strings are equal or else false
// time:     O(n)
bool comp_str(const char *str1, const char *str2) {
    assert(str1);
    assert(str2);
    while (*str1 != '\0' && *str1 == *str2) {
        // Move to the next character in each string
        str1++;
        str2++;
    }
    
    // Check if both strings reached their ends
    return *str1 == '\0' && *str2 == '\0';
}

// ma_get_latin(morse) returns the Latin character associated with the Morse
//   sequence *morse.
// requires: *morse must represent a Latin letter, space, or AR (end of
//             transmission)
// time:     O(n^2)
const char ma_get_latin(const char *morse) {
    // Your implementation goes here
    assert(morse);
    char morse_code[6] = {'\0'};
    for (int i = 0; i < 6; i++) {
        morse_code[i] = *(morse + i);
    }

    for (int i = 0; i < MORSE_ALPHABET_LENGTH; ++i) {
        if(comp_str(MORSE_ALPHABET[i].morse, morse_code)) {
            return MORSE_ALPHABET[i].latin;
        }
    }
    return 0;
}

// === MODULE FUNCTIONS =======================================================

// See morse.h for documentation.
void morse_encode(char *morse_text, const char *plain_text) {
    // Your implementation goes here
    assert(morse_text);
    assert(plain_text);
    while (*plain_text != '\0') {
        if (*plain_text == ' ') {
            // Encode space as 'P' followed by a space
            strcat(morse_text, "P ");
        } else {
            // Encode characters and add a space after each Morse code
            strcat(morse_text, ma_get_morse(*plain_text));
            strcat(morse_text, " ");
        }
        ++plain_text;
    }
    // Ending with '\O' into morse
    strcat(morse_text,ma_get_morse('\0'));
}


// See morse.h for documentation.
void morse_decode(char *plain_text, const char *morse_text) {
    // Your implementation goes here
    assert(morse_text);
    assert(plain_text);
    
    // Create a buffer to store one Morse character sequence at a time
    char buffer[6] = {'\0'};
    int buffer_index = 0;

    // Go through the Morse code, character by character
    for (const char *ptr = morse_text; *ptr != '\0'; ++ptr) {
        if (*ptr == ' ') {
            // End of Morse sequence for a character
            buffer[buffer_index] = '\0';  // Null-terminate the buffer
            *plain_text++ = ma_get_latin(buffer);  // Decode and add to plain_text
            buffer_index = 0;  // Reset buffer index for the next Morse sequence
            // Skip subsequent spaces (which indicate end of Morse character)
            while (*(ptr + 1) == ' ') ++ptr;
            // If next character is 'P' (space), add space to plain_text and skip the 'P' and space after it
            if (*(ptr + 1) == 'P') {
                *plain_text++ = ' ';
                ptr += 2;  // Skip the 'P' and the space following it
            }
        } else if (*ptr != 'P') {
            // Accumulate Morse code into buffer
            buffer[buffer_index++] = *ptr;
        }
    } 
}
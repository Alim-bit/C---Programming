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

#include "rot13.h"
#include "cs136-trace.h"

// Your additional includes go here.
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
// See rot13.h for documentation.
void rot_13_encrypt(char *plain_text) {
    // Your implementation goes here.
    assert(plain_text);
    const char *end = plain_text;
    while (*end) { 
    ++end;
    }
    int str_len = end - plain_text;
    for (int i = 0; i < str_len; i++) {
        char ptc = *(plain_text + i);
        if (ptc >= 'A' && ptc <= 'Z') {
            ptc -= 13;
            if (ptc >= 'A' && ptc <= 'Z') {
                *(plain_text + i) = ptc;
            } else {
                *(plain_text + i) = ptc + 26;
            }
        } else if (ptc >= 'a' && ptc <= 'z') {
            ptc -= 13;
            if (ptc >= 'a' && ptc <= 'z') {
                *(plain_text + i) = ptc;
            } else {
                *(plain_text + i) = ptc + 26;
            }
        }
    }
}

// See rot13.h for documentation.
void rot_13_decrypt(char *cipher_text) {
    // Your implementation goes here.
    assert(cipher_text);
    const char *end = cipher_text;
    while (*end) { 
    ++end;
    }
    int str_len = end - cipher_text;
    for (int i = 0; i < str_len; i++) {
        char ptc = *(cipher_text + i);
        if (ptc >= 'A' && ptc <= 'Z') {
            ptc += 13;
            if (ptc >= 'A' && ptc <= 'Z') {
                *(cipher_text + i) = ptc;
            } else {
                *(cipher_text + i) = ptc - 26;
            }
        } else if (ptc >= 'a' && ptc <= 'z') {
            ptc += 13;
            if (ptc >= 'a' && ptc <= 'z') {
                *(cipher_text + i) = ptc;
            } else {
                *(cipher_text + i) = ptc - 26;
            }
        }
    }
}
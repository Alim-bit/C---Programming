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

#include "parser.h"
#include "cs136-trace.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// See parser.h for documentation.
void remove_comments(char *code) {
    // Your implementation goes here.
    assert(code);
    int i = 0, j = 0;
    bool in_single_line_comment = false, in_multi_line_comment = false, in_string_literal = false;

    while (code[i] != '\0') {
        if (in_single_line_comment && code[i] == '\n') {
            in_single_line_comment = false;
            code[j++] = code[i++];
        } else if (in_multi_line_comment && code[i] == '*' && code[i + 1] == '/') {
            in_multi_line_comment = false;
            i += 2; // Skip closing comment tags
        } else if (!in_string_literal && !in_single_line_comment && !in_multi_line_comment) {
            if (code[i] == '/' && code[i + 1] == '/') {
                in_single_line_comment = true;
                i += 2; // Skip opening comment tags
            } else if (code[i] == '/' && code[i + 1] == '*') {
                in_multi_line_comment = true;
                i += 2; // Skip opening comment tags
            } else if (code[i] == '"') {
                in_string_literal = true;
                code[j++] = code[i++];
            } else {
                code[j++] = code[i++];
            }
        } else if (in_string_literal) {
            if (code[i] == '"' && code[i - 1] != '\\') { // Check for escape character
                in_string_literal = false;
            }
            code[j++] = code[i++];
        } else {
            i++; // Skip characters inside comments
        }
    }
    code[j] = '\0';
}
#include <stdio.h>
#include "rot13.h"

int main(void) {
    char message[1000] = {'\0'};
    int message_len = 0;
    while (scanf("%c", message + message_len) != EOF && message_len < 1000) {
        ++message_len;
    }

    printf("Original message:\n%s\n\n", message);
    
    rot_13_encrypt(message);
    printf("Encrypted message:\n%s\n\n", message);
    
    rot_13_decrypt(message);
    printf("Decrypted message:\n%s\n", message);
}
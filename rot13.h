
// rot_13_encrypt(plain_text) encrypts the string *plain_text using the ROT-13
//   substitution cipher.
// effects:  mutates *plain_text
// time:     O(n)
void rot_13_encrypt(char *plain_text);

// rot_13_decrypt(cipher_text) decrypts the string *cipher_text using the
//   ROT-13 substitution cipher.
// effects:  mutates *cipher_text
// time:     O(n)
void rot_13_decrypt(char *cipher_text);
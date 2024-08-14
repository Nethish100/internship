#include <stdio.h>
#include <string.h>

// Function to encrypt plaintext using monoalphabetic cipher
void encrypt(char plaintext[], char key[], char ciphertext[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = key[plaintext[i] - 'A'];
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = key[plaintext[i] - 'a'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0'; // Add null terminator
    printf("Ciphertext: %s\n", ciphertext);
}

// Function to decrypt ciphertext using monoalphabetic cipher
void decrypt(char ciphertext[], char key[], char plaintext[]) {
    int i, j;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            for (j = 0; key[j] != '\0'; j++) {
                if (ciphertext[i] == key[j]) {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            for (j = 0; key[j] != '\0'; j++) {
                if (ciphertext[i] == key[j] + 'a' - 'A') {
                    plaintext[i] = 'a' + j;
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0'; // Add null terminator
    printf("Decrypted plaintext: %s\n", plaintext);
}

int main() {
    char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char ciphertext[strlen(plaintext) + 1]; // +1 for null terminator
    char decryptedtext[strlen(plaintext) + 1]; // +1 for null terminator

    printf("Plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);

    return 0;
}






//Section C
#include<stdio.h>
#include<ctype.h>
char encryptChar(char c, char key[])
{
if (c >= 'A' && c <= 'Z')
return key[c - 'A'];
else if (c >= 'a' && c <= 'z')
return key[c - 'a'] + ('a' - 'A');
else
return c;
}

char decryptChar(char c, char key[])
{
for (int i = 0; i < 26; i++){
if (c == key[i] || c == key[i] + ('a' - 'A'))
return i + (c >= 'a' ? 'a' : 'A');
}

return c;
}

void encrypt(char *plaintext, char *key)
{
for (int i = 0; plaintext[i]; i++)
plaintext[i] = encryptChar(plaintext[i], key);
}

void decrypt(char *ciphertext, char *key)
{
for (int i = 0; ciphertext[i]; i++)
ciphertext[i] = decryptChar(ciphertext[i], key);
}

int main()
{
char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
char ciphertext[sizeof(plaintext)];

encrypt(plaintext, key);
printf("Encrypted Message: %s\n", plaintext);

decrypt(plaintext, key);
printf("Decrypted Message: %s\n", plaintext);

return 0;
}

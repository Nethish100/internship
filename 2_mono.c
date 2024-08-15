
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


#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Include for tolower function

#define MAX_SIZE 10

void encrypt(char *plaintext, char *ciphertext, int keyMatrix[MAX_SIZE][MAX_SIZE], int keySize) {
    int len = strlen(plaintext);
    int blockSize = keySize;
    
    // Padding the plaintext if necessary
    while (len % blockSize != 0) {
        plaintext[len] = 'x';
        len++;
    }
    plaintext[len] = '\0'; // Update null terminator after padding
    
    int numBlocks = len / blockSize;
    int i, j, k;
    int sumArr[MAX_SIZE];

    for (i = 0; i < numBlocks; i++) {
        for (j = 0; j < keySize; j++) {
            sumArr[j] = 0;
        }

        for (j = 0; j < keySize; j++) {
            for (k = 0; k < keySize; k++) {
                // Convert each character to lowercase before processing
                sumArr[j] += keyMatrix[j][k] * (tolower(plaintext[i * blockSize + k]) - 'a');
            }
            sumArr[j] %= 26;
        }

        for (j = 0; j < keySize; j++) {
            ciphertext[i * blockSize + j] = (char)(sumArr[j] + 'a');
        }
    }
    ciphertext[len] = '\0';
}

int main() {
    int keySize, i, j;
    int keyMatrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the size of the key matrix: ");
    scanf("%d", &keySize);

    printf("Enter the key matrix elements:\n");
    for (i = 0; i < keySize; i++) {
        for (j = 0; j < keySize; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }
   getchar();
   char plaintext[100], ciphertext[100];

    printf("Enter your Plaintext: ");
    fgets(plaintext,sizeof(plaintext),stdin);
    //scanf(" %[^\n]s", plaintext);
    plaintext[strcspn(plaintext,"\n")]='\0';

    encrypt(plaintext, ciphertext, keyMatrix, keySize);

    printf("Your CipherText is: %s\n", ciphertext);
    return 0;
}

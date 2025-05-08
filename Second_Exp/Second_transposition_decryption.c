#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    char wrd[] = "MEGABUCK";
    char cipher[20][8];  // max rows = 20, 8 columns (length of key)
    int seq[8];
    int i, j, cnt, c;

    int keyLen = strlen(wrd);

    // Step 1: Generate column sequence based on alphabetical order of the keyword
    for (i = 0; i < keyLen; i++) {
        cnt = 0;
        for (j = 0; j < keyLen; j++) {
            if (wrd[i] > wrd[j])
                ++cnt;
        }
        seq[i] = cnt;
    }

    // Step 2: Read encrypted data
    printf("\nEnter encrypted data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove newline
    cnt = strlen(data);

    if (cnt % keyLen != 0) {
        printf("\nError: Invalid Input Length (must be multiple of keyword length)\n");
        return 1;
    }

    int rows = cnt / keyLen;

    // Step 3: Fill the cipher matrix column-wise based on seq
    for (i = 0; i < keyLen; i++) {
        // Find original column position using seq
        for (c = 0; c < keyLen; c++) {
            if (seq[c] == i)
                break;
        }
        for (j = 0; j < rows; j++) {
            cipher[j][c] = data[i * rows + j];
        }
    }

    // Step 4: Reconstruct original data row-wise
    printf("\nDecrypted data: ");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < keyLen; j++) {
            if (cipher[i][j] != '.')
                printf("%c", cipher[i][j]);
        }
    }
    printf("\n");

    return 0;
}
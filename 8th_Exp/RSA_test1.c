#include <stdio.h>
#include <stdlib.h>

// Function to find gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find modular inverse
int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

// Function to perform modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int p, q;

    // Step 1: User inputs p and q
    printf("Enter first prime number (p): ");
    scanf("%d", &p);
    printf("Enter second prime number (q): ");
    scanf("%d", &q);

    int n = p * q; // Step 2: Compute n
    int phi = (p - 1) * (q - 1); // Step 3: Compute φ(n)

    // Step 4: Choose e such that gcd(e, phi) = 1
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    // Step 5: Find modular inverse d
    int d = modInverse(e, phi);
    if (d == -1) {
        printf("Modular inverse of e doesn't exist.\n");
        return 1;
    }

    printf("Public Key: (e=%d, n=%d)\n", e, n);
    printf("Private Key: (d=%d, n=%d)\n", d, n);

    // Step 6: Get plaintext input
    int plaintext;
    printf("Enter plaintext (as integer < %d): ", n);
    scanf("%d", &plaintext);

    // Step 7: Encrypt plaintext
    int cipher = modExp(plaintext, e, n);
    printf("Encrypted Cipher Text: %d\n", cipher);

    // Step 8: Decrypt ciphertext
    int decrypted = modExp(cipher, d, n);
    printf("Decrypted Plaintext: %d\n", decrypted);

    return 0;
}
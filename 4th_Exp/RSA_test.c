// RSA Encryption and Decryption in C

/*Expected output: 
Enter a prime number p: 17
Enter a prime number q: 19
n (p * q) = 323
phi (p-1)(q-1) = 288
Enter a number e (1 < e < 288) such that gcd(e, phi) = 1: 5
Public Key (e, n) = (5, 323)
Private Key (d, n) = (173, 323)
Enter the message (numeric form) to encrypt: 123
Encrypted Message: 225
Decrypted Message: 123
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate gcd of a and b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modulo inverse of e
int modInverse(int e, int phi) {
    int t1 = 0, t2 = 1, r1 = phi, r2 = e, q, t, r;
    while (r2 > 0) {
        q = r1 / r2;
        r = r1 % r2;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
        r1 = r2;
        r2 = r;
    }
    if (r1 == 1)
        return (t1 + phi) % phi;
    return -1;  // Inverse doesn't exist
}

// Function to calculate power of a number modulo n (used for encryption and decryption)
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// Function to perform RSA encryption and decryption
void rsaEncryptionDecryption() {
    int p, q, n, phi, e, d;
    long long message, encryptedMessage, decryptedMessage;

    // Step 1: Choose prime numbers p and q
    printf("Enter a prime number p: ");
    scanf("%d", &p);
    while (!isPrime(p)) {
        printf("p is not prime. Enter a prime number p: ");
        scanf("%d", &p);
    }

    printf("Enter a prime number q: ");
    scanf("%d", &q);
    while (!isPrime(q)) {
        printf("q is not prime. Enter a prime number q: ");
        scanf("%d", &q);
    }

    // Step 2: Calculate n = p * q
    n = p * q;
    printf("n (p * q) = %d\n", n);

    // Step 3: Calculate phi = (p-1) * (q-1)
    phi = (p - 1) * (q - 1);
    printf("phi (p-1)(q-1) = %d\n", phi);

    // Step 4: Choose e such that 1 < e < phi and gcd(e, phi) = 1
    printf("Enter a number e (1 < e < %d) such that gcd(e, phi) = 1: ", phi);
    scanf("%d", &e);
    while (gcd(e, phi) != 1) {
        printf("e and phi are not coprime. Enter another e: ");
        scanf("%d", &e);
    }

    // Step 5: Calculate d such that (d * e) % phi = 1
    d = modInverse(e, phi);
    if (d == -1) {
        printf("Modular inverse of e doesn't exist.\n");
        return;
    }

    printf("Public Key (e, n) = (%d, %d)\n", e, n);
    printf("Private Key (d, n) = (%d, %d)\n", d, n);

    // Encryption Step: C = (message^e) % n
    printf("Enter the message (numeric form) to encrypt: ");
    scanf("%lld", &message);
    encryptedMessage = powerMod(message, e, n);
    printf("Encrypted Message: %lld\n", encryptedMessage);

    // Decryption Step: P = (C^d) % n
    decryptedMessage = powerMod(encryptedMessage, d, n);
    printf("Decrypted Message: %lld\n", decryptedMessage);
}

int main() {
    rsaEncryptionDecryption();
    return 0;
}

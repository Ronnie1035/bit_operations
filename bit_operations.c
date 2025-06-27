#include <stdio.h>

// Bit işlemi fonksiyon prototipleri
int SetBit(int x, int position);
int ClearBit(int x, int position);
int FlipBit(int x, int position);
int BitCount(int x);
int GetBit(int x, int position);

// Ana fonksiyon
int main() {
    int x = 10; // 1010 in binary

    printf("Initial value of x: %d (binary approx)\n", x);

    // Set bit at position 1
    x = SetBit(x, 1);  // zaten 1 olabilir ama örnek olarak
    printf("After SetBit at position 1: %d\n", x);

    // Clear bit at position 3
    x = ClearBit(x, 3); // 1010 -> 0010 = 2
    printf("After ClearBit at position 3: %d\n", x);

    // Flip bit at position 0
    x = FlipBit(x, 0);  // 0010 -> 0011 = 3
    printf("After FlipBit at position 0: %d\n", x);

    // Get bit at position 1
    int bit = GetBit(x, 1); // 0011 -> bit 1 = 1
    printf("GetBit at position 1: %d\n", bit);

    // Bit count (kaç bit gerekir)
    int bits = BitCount(x); // 3 için 2 bit yeterli: 11
    printf("BitCount of x: %d\n", bits);

    return 0;
}

// Verilen konumdaki biti 1 yap
int SetBit(int x, int position) {
    int mask = 1 << position;
    return x | mask;
}

// Verilen konumdaki biti 0 yap
int ClearBit(int x, int position) {
    int mask = 1 << position;
    return x & ~mask;
}

// Verilen konumdaki biti ters çevir (1 ↔ 0)
int FlipBit(int x, int position) {
    int mask = 1 << position;
    return x ^ mask;
}

// Sayının kaç bit ile temsil edildiğini bul (MSB + 1)
int BitCount(int x) {
    int i = 0;
    while ((1 << i) <= x) {
        i++;
    }
    return i;
}

// Belirli bir konumdaki bitin değerini getir (0 ya da 1)
int GetBit(int x, int position) {
    return (x >> position) & 1;
}

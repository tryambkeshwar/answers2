<!-- 1. Write a program to print exponent part of double variable in hexadecimal and binary format.
lets say we have x = 0.7, the exponent in hex is 0x3FE and 0b01111111110
You may use the below link to validate you output
https://baseconvert.com/ieee-754-floating-point

Topics to be covered
- Pointers
- Bitwise Operators -->

#include <stdio.h>

void printExponent(double num) {
    unsigned long long* p = (unsigned long long*)&num;
    unsigned long long exponent = (*p >> 52) & 0x7FF;

    // Hexadecimal format
    printf("Hexadecimal: 0x%llX\n", exponent);

    // Binary format
    printf("Binary: 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}


// 2. Write a program to swap any type of data passed to an function.

// Topics to be covered
// - Pointers
// - Type Casting

#include <stdio.h>

void swap(void* ptr1, void* ptr2, size_t size) {
    char* temp = (char*)malloc(size);
    memcpy(temp, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, temp, size);
    free(temp);
}

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 3.14, y = 2.71;
    printf("Before swap: x = %lf, y = %lf\n", x, y);
    swap(&x, &y, sizeof(double));
    printf("After swap: x = %lf, y = %lf\n", x, y);

    char c1 = 'A', c2 = 'B';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}

// 3. Write a program to sum every alternate elements of a given array starting for element 0
// For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be 10 + 30 + 50 = 90

// Topics to be covered
// - Arrays
// - Loops
// - Basic Operators

 #include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }

    printf("Sum of alternate elements: %d\n", sum);

    return 0;
}

// 4. Write a program to find total number of bits set in a given array.
// Say we have a array of 3 elements
// a[3] = {0x1, 0xF4, 0x10001};
// The total number of set bits in the given array is
// 1 bit in 0x01, 5 in 0xF4, 2 in 0x10001, so the total is 1 + 5 + 2 = 8 bits

// Topics to be covered
// - Arrays
// - Loops
// - Bitwise Operators

#include <stdio.h>

int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    unsigned int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);
    int totalBits = 0;

    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(arr[i]);
    }

    printf("Total number of set bits: %d\n", totalBits);

    return 0;
}


 

 
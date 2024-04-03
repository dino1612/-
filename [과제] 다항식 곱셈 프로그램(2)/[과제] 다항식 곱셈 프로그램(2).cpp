#include <stdio.h>
#include <stdlib.h>

// Function to print the polynomial
void print_polynomial(int* poly, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i != 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

// Function to multiply two polynomials
void multiply_polynomials(int* poly1, int n1, int* poly2, int n2, int* result) {
    // Initialize the product polynomial
    for (int i = 0; i < n1 + n2 - 1; i++) {
        result[i] = 0;
    }

    // Multiply the polynomials
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

int main() {
    // Example 1
    int poly1[] = { 1, 2, 3, 4 }; // 1 + 2x + 3x^2 + 4x^3
    int poly2[] = { 8, 2, 3 };    // 8 + 2x + 3x^2

    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);
    int* result1 = (int*)calloc(size1 + size2 - 1, sizeof(int));

    multiply_polynomials(poly1, size1, poly2, size2, result1);

    printf("Product of polynomial 1 is: ");
    print_polynomial(result1, size1 + size2 - 1);

    // Free allocated memory
    free(result1);

    // Example 2
    int poly3[] = { 1, 0, 9, 5, 0, 0, 7 }; // 1 + 9x^2 + 5x^3 + 7x^6
    int poly4[] = { 10, 1, 2, 5 };         // 10 + x + 2x^2 + 5x^3

    int size3 = sizeof(poly3) / sizeof(poly3[0]);
    int size4 = sizeof(poly4) / sizeof(poly4[0]);
    int* result2 = (int*)calloc(size3 + size4 - 1, sizeof(int));

    multiply_polynomials(poly3, size3, poly4, size4, result2);

    printf("Product of polynomial 2 is: ");
    print_polynomial(result2, size3 + size4 - 1);

    // Free allocated memory
    free(result2);

    return 0;
}
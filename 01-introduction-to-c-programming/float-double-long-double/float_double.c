#include <stdio.h>

int main() {
    // Same literal value stored into each type, to see how much of it
    // actually survives the type's precision.
    float var1 = 3.1415926535897932;
    double var2 = 3.1415926535897932;
    long double var3 = 3.141592653589793213456;

    // sizeof returns size_t, not int; %d expects int. On a 64-bit system
    // size_t is 8 bytes while int is 4, so this mismatch is undefined
    // behavior (it happens to print correctly here, but isn't guaranteed
    // to). %zu is the correct specifier for size_t.
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(long double));

    // float keeps ~6-7 significant digits, so this is already wrong past
    // the 7th digit.
    printf("%.16f\n", var1);
    // double keeps ~15-16 significant digits, correct through here.
    printf("%.16f\n", var2);
    // long double (16 bytes on x86-64) has more precision than double,
    // but %Lf still prints past what's meaningfully accurate.
    printf("%.21Lf\n", var3);
}
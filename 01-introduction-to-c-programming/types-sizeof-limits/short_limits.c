#include <stdio.h>
#include <limits.h>

int main() {
    short int var1 = SHRT_MIN;
    short int var2 = SHRT_MAX;
    printf("Range of signed short integers: %d to %d\n", var1, var2);

    return 0;
}
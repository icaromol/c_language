#include <stdio.h>

int main() {
    // 4 and 9 are int literals, so this is integer division: truncates
    // toward zero, giving 0 (not 0.44...) before it's ever stored.
    int var1 = 4/9;
    printf("%d\n", var1);

    // Still integer division: 4/9 is computed as int (= 0) first, THEN
    // converted to float. Declaring var2 as float doesn't change how the
    // expression on the right was evaluated.
    float var2 = 4/9;
    printf("%.2f\n", var2);

    // 4.0 and 9.0 are double literals, so this is real floating-point
    // division: 0.4444..., converted to float when stored in var3.
    float var3 = 4.0/9.0;
    printf("%.2f\n", var3);
}
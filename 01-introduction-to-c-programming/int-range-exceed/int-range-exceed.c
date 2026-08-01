#include <stdio.h>

int main() {
    int signed sgn_var = 2147483647; // This value doesnt exceeds the range of a signed int
    int signed sgn_var_exceeds = 2147483648; // This value exceeds the range of a signed int
    printf("sgn_var: %d\n", sgn_var);
    printf("sgn_var_exceeds: %d\n", sgn_var_exceeds);

    unsigned int usgn_var = 4294967295; // This value doesnt exceeds the range of an unsigned int
    unsigned int usgn_var_exceeds = 4294967296; // This value exceeds the range of a signed int
    printf("usgn_var: %u\n", usgn_var);
    printf("usgn_var_exceeds: %u\n", usgn_var_exceeds);
    
    return 0;
}
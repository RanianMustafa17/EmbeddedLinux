#include <stdio.h>
#include <operations.h>
int main() {
    // Example usage
    int result = modulus(10, 3);
    printf("Modulus: %d\n", result);

    result = addFunc(10, 3);
    printf("addfunc : %d\n", result);

    result = subFunc(10, 3);
    printf(" subtraction: %d\n", result);

     result = mulFunc(10, 3);
    printf("Multiplication: %d\n", result);

    result = divFunc(10, 3);
    printf("divition : %d\n", result);

    return 0;
}


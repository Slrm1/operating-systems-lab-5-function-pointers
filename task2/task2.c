#include <stdio.h>
#include <stdlib.h>

/* A common signature lets every arithmetic routine occupy one dispatch table. */
typedef int (*Operation)(int, int);

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exit_program(int a, int b);

int main(void)
{
    const int a = 6;
    const int b = 3;
    char choice = '4';
    unsigned int index;
    int x;
    Operation operations[] = {add, subtract, multiply, divide, exit_program};

    printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
    fflush(stdout);
    scanf(" %c", &choice);

    /* Convert the requested character to a safe dispatch-table index. */
    index = ((unsigned char)choice - (unsigned char)'0') % 5U;
    x = operations[index](a, b);
    printf("x = %d\n", x);
    return 0;
}

int add(int a, int b)
{
    printf("Adding 'a' and 'b'\n");
    return a + b;
}

int subtract(int a, int b)
{
    printf("Subtracting 'b' from 'a'\n");
    return a - b;
}

int multiply(int a, int b)
{
    printf("Multiplying 'a' and 'b'\n");
    return a * b;
}

int divide(int a, int b)
{
    printf("Dividing 'a' by 'b'\n");
    return a / b;
}

int exit_program(int a, int b)
{
    (void)a;
    (void)b;
    exit(EXIT_SUCCESS);
}

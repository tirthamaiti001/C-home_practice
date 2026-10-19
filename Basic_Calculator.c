#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    if (b == 0) return -99999;  // Error flag
    return a / b;
}
int calculate(int a, int b, char operation) {
    switch (operation) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/': return divide(a, b);
        default: return -99999;  // Error flag for invalid operation
    }
}
int main() {
    int a, b;
    char op;
    if (scanf("%d", &a) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    if (scanf(" %c", &op) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    if (scanf("%d", &b) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    if (op == 'q')  return 0;

    int result = calculate(a, b, op);

    if (result == -99999)   printf("Invalid input\n");
    else    printf("Ans: %d\n", result);

    return 0;
}

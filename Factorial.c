// Calculate the factorial of a number given by user.
#include <stdio.h>

int fact(int n) {
    if (n == 0) return 1; //Base Case

    int factNm = n * fact(n - 1); //Recurtion
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("factorial of %d: %d", n, fact(n)); //Call by Value
    
    return 0;
}

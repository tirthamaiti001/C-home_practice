//Number (1-100) guessing game.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Guess a number between 1 to 100...\nLet's play the game :)\nRemember: Your point increases by taking less no. in guessing.\n");
    
    srand(time(0));    // Seed the random number generator with the current time
    int num = (rand() % 100) + 1, n, count = 0;
    do {
        if(printf("Guess the no.: "))    scanf("%d", &n);
        count++;
        if(n < num) printf("Enter a bigger number!!\n");
        else if(n > num) printf("Enter a smaller number!!\n");
    } while(n != num);
    printf("Your point: %d", 100 - count);
    
    return 0;
}

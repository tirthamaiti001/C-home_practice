#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // Used for Sleep function

int i, j, gameover, score, height = 20, width = 20;
int x, y, fruitx, fruity, flag, tailX[100], tailY[100], CountTail = 0;

void setup()    {
    gameover = 0;
    x = width / 2;
    y = height / 2;
label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0;
}// Function to set up the game at the start

void draw()     {
    system("cls"); // Clear the screen
    for (i = 0; i < height; i++)    {
        for (j = 0; j < width; j++)      {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)  printf("#"); // Wall
            else    {
                if (i == x && j == y)   printf("O"); // Snake Head
                else if (i == fruitx && j == fruity)    printf("F"); // Fruit
                else    {
                    int ch = 0;
                    for (int k = 0; k < CountTail; k++)     {
                        if (i == tailX[k] && j == tailY[k])     {
                            printf("o"); // Tail
                            ch = 1;
                        }
                    }// Check if we need to print the tail here
                    if (ch == 0)    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("SCORE = %d\nPress X to Quit the game.", score);
}// Function to draw the boundary, snake, and fruit

void input()    {
    if (_kbhit())   {
        switch (_getch())   {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    } // Checks if a key is pressed
}// Function to take User Input

void MakeLogic()    {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < CountTail; i++)    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (flag)    {
    case 1:
        y--; // Left
        break;
    case 2:
        x++; // Down
        break;
    case 3:
        y++; // Right
        break;
    case 4:
        x--; // Up
        break;
    default:
        break;
    }// Move the head based on flag
    if (x < 0 || x > width || y < 0 || y > height)      gameover = 1;    // Check if snake hits the wall
    for (int i = 0; i < CountTail; i++)    {
        if (x == tailX[i] && y == tailY[i])     gameover = 1;    // Check if snake hits its own tail
    }
    if (x == fruitx && y == fruity)    {
    label3:
        fruitx = rand() % 20;
        if (fruitx == 0)    goto label3;
    label4:
        fruity = rand() % 20;
        if (fruity == 0)    goto label4;
        score += 10;
        CountTail++;
    }// Check if snake eats the fruit
}

int main()  {
    setup();
    while (!gameover)    {
        draw();
        input();
        MakeLogic();
        Sleep(100); // Slow down the game slightly
    }
    return 0;
}
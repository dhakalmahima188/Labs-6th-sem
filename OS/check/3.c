#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Added for kbhit() and getch() functions

int height = 20, width = 20, x, y, fruitx, fruity, flag, gameEnd = 0, score; // Initialized gameEnd to 0
int tailx[100], taily[100], piece = 0;

void makelogic()
{
    int i;
    int prevx, prevy, prev2x, prev2y;
    prevx = tailx[0];
    prevy = taily[0];
    tailx[0] = x;
    taily[0] = y;
    for (i = 1; i <= piece; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch (flag)
    {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
    }
    if (x == 0 || x == height-1 || y == 0 || y == width-1) // Fixed boundary conditions
    {
        gameEnd = 1;
    }
    if (x == fruitx && y == fruity)
    {
    label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3; // Fixed label name

    label4: // Moved label outside of if statement
        fruity = rand() % 20;
        if (fruity == 0)
            goto label4; // Fixed label name

        score += 10;
        piece++; // Increment tail length
    }
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
            case 'w':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'a':
                flag = 3;
                break;
            case 'd':
                flag = 4;
                break;
        }
    }
}

void setup()
{
    x = height / 2;
    y = width / 2;

label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1; // Fixed label name

label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2; // Fixed label name

    gameEnd = 0; // Reset gameEnd
    score = 0;
    piece = 0; // Reset tail length
}

void draw()
{
    system("cls");
    int i, j, k, ch;
    for (i = 0; i < height; i++) // Fixed boundary conditions
    {
        for (j = 0; j < width; j++) // Fixed boundary conditions
        {
            if (i == 0 || i == height-1 || j == 0 || j == width-1)
            {
                printf("#"); // Changed to a wall character
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("0");
                }
                else if (i == fruitx && j == fruity)
                {
                    printf("*"); // Changed to

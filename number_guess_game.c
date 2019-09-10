#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void guess(int num, int random_num);
void record_of_prev_guesses(int *arr, int turns);
char congratulations();
char game_over();

int main() {
    //This will generate random numbers from 1 to 100
    srand(time(0));

    int random_num = (rand()%100)+1;
    int turn = 1;
    int prev_guess[10];
    int number;
    char option = NULL;

    while(1)
    {
        switch(option)
        {
        case 'E':
            break;

        case 'R':
            continue;

        default:
            while(1)
            {
                system("clear");
                printf("Enter a number : ");
                scanf(" %d", &number);

                if(number > 100 || number < 1)
                    printf("\nPlease enter a number which is in between 1 - 100");
                else
                    prev_guess[turn-1] = number;

                guess(number, random_num);
                record_of_prev_guesses(prev_guess, turn);

                if(number == random_num){
                    congratulations();
                    break;
                }
                else if(turn >10){
                    game_over();
                    break;
                }

                getch();
                turn++;
            }
        }
    }

    getch();
    return 0;
}

void guess(int num, int random_num)
{
    if(num < random_num)
        printf("\n Lower \n");
    else if(num > random_num)
        printf("\n Higher \n");
    else
        printf("\n You Guessed it Right!");
}

void record_of_prev_guesses(int *arr, int turns)
{
    int i=0;
    printf("\n\t");
    for(i; i<turns; i++)
    {
        printf(" %d", arr[i]);
    }
}

char congratulations()
{
    printf("\n");
    printf("\t\t*********************\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*  Congratulations  *\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*********************\t\t\n");

    char option;
    printf("\n\t Press R to restart or E to end this game!\t\n");
    scanf(" %c", &option);

    return option;
}

char game_over()
{
    printf("\n");
    printf("\t\t*********************\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*     Game Over     *\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*                   *\t\t\n");
    printf("\t\t*********************\t\t\n");

    char option;
    printf("\n\t Press R to restart or E to end this game!\t\n");
    scanf(" %c", &option);

    return option;
}


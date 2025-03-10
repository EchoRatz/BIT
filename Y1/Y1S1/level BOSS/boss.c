#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CARDS 10
#define BUFFER_SIZE 50

int calculateBestScore;

int CalculateCardValue(char hand[][3], int numCards)
{
    int totalPoint = 0, acecount = 0;

    for (int i = 0; i < numCards; i++)
    {
        int cardvalue = GetCardValue(hand[i]);
        if (cardvalue == -1)
        {
            printf("Input Error!\n");
            return -1;
        }
        totalPoint += cardvalue;
        if (cardvalue == 1)
        {
            acecount++;
        }
    }
    while (acecount > 0 && totalPoint + 10 <= 21)
    {
        totalPoint = +10;
        acecount--;
    }
    return totalPoint;
}

void determinewinner(int playerApoints, int playerBpoints)
{
    if (playerApoints > 21)
        playerApoints = 0;
    if (playerBpoints > 21)
        playerBpoints = 0;

    if (playerApoints > playerBpoints)
    {
        printf("A wins by %d points!\n", playerApoints - playerBpoints);
    }
    else if (playerApoints < playerBpoints)
    {
        printf("B wins by %d points!\n", playerBpoints - playerApoints);
    }
    else
    {
        printf("Tie!\n");
    }
}

void blackjack()
{
    char inputLine[20];
    char cardPlayerA[3][3], cardPlayerB[3][3];
    int numCardsA = 0, numCardsB = 0;

    printf("You're playing Blackjack.\n");
    printf("Please input cards for each player:\n");

    // Debug print
    for (int i = 0; i < numCardsA; i++)
    {
        printf("Player A Card %d: %s\n", i + 1, cardPlayerA[i]);
    }
    for (int i = 0; i < numCardsB; i++)
    {
        printf("Player B Card %d: %s\n", i + 1, cardPlayerB[i]);
    }

    int playerApoints = CalculateCardValue(cardPlayerA, numCardsA);
    int playerBpoints = CalculateCardValue(cardPlayerB, numCardsB);

    printf("Test Card Value H10: %d\n", GetCardValue("H10")); // Should print 10
    printf("Test Card Value HJ: %d\n", GetCardValue("HJ"));   // Should print 10

    if (playerApoints != -1 && playerBpoints != -1)
    {
        determinewinner(playerApoints, playerBpoints);
    }
    else
    {
        printf("Input Error!\n");
    }
}
void tractor()
{
    printf("You're playing Tractor.\n");
}

void evaluateTractorhand(int hand[]);

int main()
{
    int choice;

    do
    {
        printf("1. Blackjack\n");
        printf("2. Tractor\n");
        printf("0. Exit\n");
        printf("Input your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            blackjack();
            break;
        case 2:
            tractor();
            break;
        case 0:
            break;
        default:
            printf("Wrong Input. Input Again.\n");
        }
    } while (choice != 0);
}
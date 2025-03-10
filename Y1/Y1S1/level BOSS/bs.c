#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 10
#define BUFFER_SIZE 50
#define CARD_STR_LEN 3

int getCardValue(char *card);
int calculateScore(int cards[], int cardCount);

void blackjack()
{
    char playerACardsStr[MAX_CARDS][CARD_STR_LEN], playerBCardsStr[MAX_CARDS][CARD_STR_LEN];
    int playerACards[MAX_CARDS], playerBCards[MAX_CARDS];
    int playerACount = 0, playerBCount = 0;
    char input[BUFFER_SIZE];

    // PlayerA card input
    printf("Enter Player A's cards (e.g., H10 HJ): \n");
    fgets(input, BUFFER_SIZE, stdin);
    char *token = strtok(input, " ");
    while (token != NULL && playerACount < MAX_CARDS)
    {
        strncpy(playerACardsStr[playerACount], token, CARD_STR_LEN);
        playerACardsStr[playerACount][CARD_STR_LEN - 1] = '\0'; // Ensuring null-termination
        playerACount++;
        token = strtok(NULL, " ");
    }

    // PlayerB card input
    printf("Enter Player B's cards (e.g., D10 DK DA): \n");
    fgets(input, BUFFER_SIZE, stdin);
    token = strtok(input, " ");
    while (token != NULL && playerBCount < MAX_CARDS)
    {
        strncpy(playerBCardsStr[playerBCount], token, CARD_STR_LEN);
        playerBCardsStr[playerBCount][CARD_STR_LEN - 1] = '\0'; // Ensuring null-termination
        playerBCount++;
        token = strtok(NULL, " ");
    }

    // Print Player A's cards
    printf("Player A's cards: ");
    for (int i = 0; i < playerACount; i++)
    {
        printf("%s ", playerACardsStr[i]);
    }
    printf("\n");

    // Print Player B's cards
    printf("Player B's cards: ");
    for (int i = 0; i < playerBCount; i++)
    {
        printf("%s ", playerBCardsStr[i]);
    }
    printf("\n");

    // Convert string representations to numeric values
    for (int i = 0; i < playerACount; i++)
    {
        playerACards[i] = getCardValue(playerACardsStr[i]);
    }
    for (int i = 0; i < playerBCount; i++)
    {
        playerBCards[i] = getCardValue(playerBCardsStr[i]);
    }

    // ... rest of the function (calculate scores and determine the winner)
}

// Rest of your code (main, calculateScore, getCardValue functions)
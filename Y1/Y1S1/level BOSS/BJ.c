#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 10
#define BUFFER_SIZE 50
#define CARD_STR_LEN 4

int getCardValue(char *card);
int calculateScore(int cards[], int cardCount);

void clearinputbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void tractor()
{
    printf("You're playing Tractor.\n");
}

int getCardValue(char *card)
{
    char valueChar = card[1];
    if (card[1] == '1' && card[2] == '0')
    {
        return 10;
    }
    else if (valueChar >= '2' && valueChar <= '9')
    {
        return valueChar - '0';
    }
    else if (valueChar == 'J' || valueChar == 'Q' || valueChar == 'K')
    {
        return 10;
    }
    else if (valueChar == 'A')
    {
        return 11;
    }
    return 0;
}

int calculateScore(int cards[], int cardCount)
{
    int score = 0, ace = 0;

    for (int i = 0; i < cardCount; i++)
    {
        int cardValue = cards[i];
        score += cardValue;
        if (cardValue == 11)
        {
            ace++;
        }
    }

    while (score > 21 && ace > 0)
    {
        score -= 10;
        ace--;
    }

    return score;
}

int isCardValid(char *card)
{
    if (strlen(card) != 2 && strlen(card) != 3)
        return 0;

    char suit = card[0];
    if (suit != 'H' && suit != 'D' && suit != 'C' && suit != 'S')
        return 0;

    char value = card[1];
    if ((value >= '2' && value <= '9') || value == 'J' || value == 'Q' || value == 'K' || value == 'A')
    {
        return 1;
    }
    else if (strlen(card) == 3)
    {
        return card[1] == '1' && card[2] == '0';
    }

    return 0;
}

int inputCards(int playerCardsStr[MAX_CARDS][CARD_STR_LEN], int *playerCount)
{
    char input[BUFFER_SIZE];

    if (fgets(input, BUFFER_SIZE, stdin) == NULL)
    {
        return 0;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    char *token = strtok(input, " ");
    while (token != NULL && *playerCount < MAX_CARDS)
    {
        if (isCardValid(token))
        {
            strncpy(playerCardsStr[*playerCount], token, CARD_STR_LEN - 1);
            playerCardsStr[*playerCount][CARD_STR_LEN - 1] = '\0';
            (*playerCount)++;
        }
        else
        {
            printf("Input Error!\n");
            return 0;
        }
        token = strtok(NULL, " ");
    }
    return 1;
}

int isBJ(int playerCards[], int playerCount)
{
    if (playerCount == 2 && ((playerCards[0] == 11 && playerCards[1] >= 10) || (playerCards[1] == 11 && playerCards[0] >= 10)))
    {
        return 1;
    }
    return 0;
}

void blackjack()
{
    int invalidInput = 0;

    int playerACardsStr[MAX_CARDS][CARD_STR_LEN], playerBCardsStr[MAX_CARDS][CARD_STR_LEN];
    int playerACards[MAX_CARDS], playerBCards[MAX_CARDS];
    int playerACount = 0, playerBCount = 0;
    char input[BUFFER_SIZE];

    printf("You're playing Blackjack.\n");
    printf("Please input cards for each player:\n");

    // PlayerA card input
    if (!inputCards(playerACardsStr, &playerACount))
    {
        return;
    }

    // PlayerB card input
    if (!inputCards(playerBCardsStr, &playerBCount))
    {
        return;
    }

    /*for (int i = 0; i < playerACount; i++)
    {
        playerACards[i] = getCardValue(playerACardsStr[i]);
        printf("Player A Card %d: %d\n", i + 1, playerACards[i]); // Debug print
    }
    for (int i = 0; i < playerBCount; i++)
    {
        playerBCards[i] = getCardValue(playerBCardsStr[i]);
        printf("Player B Card %d: %d\n", i + 1, playerBCards[i]); // Debug print
    }*/

    if (!invalidInput)
    {

        for (int i = 0; i < playerACount; i++)
        {
            playerACards[i] = getCardValue(playerACardsStr[i]);
        }
        for (int i = 0; i < playerBCount; i++)
        {
            playerBCards[i] = getCardValue(playerBCardsStr[i]);
        }

        int playerAScore = calculateScore(playerACards, playerACount);
        int playerBScore = calculateScore(playerBCards, playerBCount);

        int PlayerABJ = isBJ(playerACards, playerACount);
        int PlayerBBJ = isBJ(playerBCards, playerBCount);

        /*printf("Player A Score: %d, Blackjack: %d\n", playerAScore, PlayerABJ);
        printf("Player B Score: %d, Blackjack: %d\n", playerBScore, PlayerBBJ);*/

        if (PlayerABJ && PlayerBBJ)
        {
            printf("Tie!\n");
        }
        else if (PlayerABJ)
        {
            printf("A wins with a Blackjack!\n");
        }
        else if (PlayerBBJ)
        {
            printf("B wins with a Blackjack!\n");
        }
        else
        {
            if (playerAScore > playerBScore)
            {
                printf("A wins by %d points!\n", playerAScore - playerBScore);
            }
            else if (playerAScore < playerBScore)
            {
                printf("B wins by %d points!\n", playerBScore - playerAScore);
            }
            else
            {
                printf("Tie!\n");
            }
        }
    }
}

int main()
{
    int choice;
    char playAgain;
    do
    {
        printf("1. Blackjack\n");
        printf("2. Tractor\n");
        printf("0. Exit\n");
        printf("Input your choice: \n");

        while (1)
        {
            scanf("%d", &choice);
            clearinputbuffer();
            if (choice == 0 || choice == 1 || choice == 2)
                break; // Valid input
            printf("Wrong nput. Input again.\n");
        }

        switch (choice)
        {
        case 1:
            blackjack();
            break;
        case 2:
            tractor();
            break;
        case 0:
            return 0;
        }
        printf("Do you want to play again? (Y/N)\n");
        scanf(" %c", &playAgain);
    } while (playAgain == 'Y' || playAgain == 'y');
    return 0;
}

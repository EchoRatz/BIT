#include <stdio.h>
#include <stdlib.h>

struct Card
{
    char suite;
    char value;
};

int comparecard(const void *a, const void *b)
{
    const struct Card *cardA = (const struct Card *)a;
    const struct Card *cardB = (const struct Card *)b;

    if (cardA != cardB)
    {
        return cardB - cardA;
    }

    return cardB - cardA;
}

char findwinner(struct Card *playerA, struct Card *playerB)
{
    for (int i = 2; i >= 0; i--)
    {
        if (playerA[i].value > playerB[i].value)
        {
            return 'A';
        }
        else if (playerA[i].value < playerB[i].value)
        {
            return 'B';
        }
    }
    return 'T';
}

int Valid(char suite, char value)
{
    return !((suite == 'H' || suite == 'S' || suite == 'D' || suite == 'C') && (value == '2' || value == '3' || value == '4' || value == '5' || value == '6' || value == '7' || value == '8' || value == '9' || value == 'J' || value == 'Q' || value == 'K' || value == 'A'));
}

int Duplicate(struct Card *cards, int amount)
{
    for (int i = 0; i < amount - 1; i++)
    {
        for (int j = i + 1; j < amount; j++)
        {
            if (cards[i].suite == cards[j].suite && cards[i].value == cards[j].value)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    struct Card playerA[3];
    for (int i = 0; i < 3; i++)
    {
        scanf(" %c%c", &playerA[i].suite, &playerA[i].value);

        if (Valid(playerA[i].suite, playerA[i].value) || Duplicate(playerA, 3))
        {
            printf("Input Error!\n");
            return 1;
        }
    }

    struct Card playerB[3];
    for (int i = 0; i < 3; i++)
    {
        scanf(" %c%c", &playerB[i].suite, &playerB[i].value);

        if (Valid(playerB[i].suite, playerB[i].value) || Duplicate(playerB, 3))
        {
            printf("Input Error!\n");
            return 1;
        }
    }

    qsort(playerA, 3, sizeof(struct Card), comparecard);
    qsort(playerB, 3, sizeof(struct Card), comparecard);

    char winner = findwinner(playerA, playerB);
    if (winner == 'T')
    {
        printf("Winner is X!\n");

        printf("A:");
        for (int i = 0; i < 3; i++)
        {
            printf(" %c%c", playerA[i].suite, playerA[i].value);
        }

        printf("\n");

        printf("B:");
        for (int i = 0; i < 3; i++)
        {
            printf(" %c%c", playerB[i].suite, playerB[i].value);
        }

        printf("\n");
    }
    else
    {
        printf("Winner is %c!\n", winner);

        printf("A:");
        for (int i = 0; i < 3; i++)
        {
            printf(" %c%c", playerA[i].suite, playerA[i].value);
        }

        printf("\n");

        printf("B:");
        for (int i = 0; i < 3; i++)
        {
            printf(" %c%c", playerB[i].suite, playerB[i].value);
        }

        printf("\n");
    }
}
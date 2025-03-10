#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char allCard[52][4] = {"C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK", "CA",
                       "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK", "DA",
                       "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK", "SA",
                       "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK", "HA"};

char cardA[3][4];
char cardB[3][4];
int powerA[3];
int powerB[3];

void bubbleSortDescending(int arr[], int n);
int findPower(char arr[3][4], int power[3]);
int sameInputErrorCheck(int arr[3]);
void changeBack(char arr[3][4], int power[3]);

int main()
{

    int i, j, counter = 0, eCounter = 0;

    scanf("%s %s %s", cardA[0], cardA[1], cardA[2]);
    scanf("%s %s %s", cardB[0], cardB[1], cardB[2]);

    // find power and check ghost card error
    findPower(cardA, powerA);
    findPower(cardB, powerB);

    if (findPower(cardA, powerA) || findPower(cardB, powerB))
    {
        printf("Input Error!\n");
        return 0;
    }

    // Check Error
    sameInputErrorCheck(powerA);
    sameInputErrorCheck(powerB);

    if (sameInputErrorCheck(powerA) || sameInputErrorCheck(powerB))
    {

        printf("Input Error!\n");
        return 0;
    }

    // Sorting power
    bubbleSortDescending(powerA, 3);
    bubbleSortDescending(powerB, 3);

    // Check winner
    for (i = 0; i < 3; i++)
    {
        if (powerA[i] > powerB[i])
        {
            printf("Winner is A!\n");
            break;
        }
        else if (powerA[i] < powerB[i])
        {
            printf("Winner is B!\n");
            break;
        }
        else if (powerA[i] == powerB[i])
        {
            eCounter++;
        }
    }
    if (eCounter == 3)
        printf("Winner is X!\n");

    // change back
    changeBack(cardA, powerA);
    changeBack(cardB, powerB);

    // print  Output
    printf("A:");
    for (i = 0; i < 3; i++)
    {
        printf(" %s", cardA[i]);
    }
    printf("\n");

    printf("B:");
    for (i = 0; i < 3; i++)
    {
        printf(" %s", cardB[i]);
    }
    printf("\n");
}

void bubbleSortDescending(int arr[], int n)
{

    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findPower(char arr[3][4], int power[3])
{

    int i, j, counter = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 52; j++)
        {
            if (strcmp(arr[i], allCard[j]) == 0)
            {
                power[i] = j;
                counter++;
            }
        }
    }

    if (counter != 3)
    {
        return 1;
    }
    return 0;
}

int sameInputErrorCheck(int arr[3])
{

    if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2])
    {
        return 1;
    }
    return 0;
}

void changeBack(char arr[3][4], int power[3])
{

    int i;

    for (i = 0; i < 3; i++)
    {
        strcpy(arr[i], allCard[power[i]]);
    }
}
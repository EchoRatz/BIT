#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

long long convert(const char *num, int base)
{
    long long value = 0;
    for (int i = 0; num[i] != '\0'; i++)
    {
        char ch = toupper(num[i]);
        int digit;

        if (isdigit(ch))
        {
            digit = ch - '0';
            if (digit >= base)
            {
                return -1;
            }
        }
        else if (isalpha(ch))
        {
            digit = ch - 'A' + 10;
            if (digit < 10 || digit >= base)
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
        value = value * base + digit;
    }
    return value;
}

int main()
{
    char M[20], N[20];
    int isMNegative = 0;
    int isNNegative = 0;

    scanf("%s %s", M, N);

    if (M[0] == '-')
    {
        isMNegative = 1;
    }

    if (N[0] == '-')
    {
        isNNegative = 1;
    }

    char *numM = isMNegative ? M + 1 : M;
    char *numN = isNNegative ? N + 1 : N;

    int found = 0;
    for (int baseM = 2; baseM <= 36 && !found; baseM++)
    {
        long long decM = convert(numM, baseM);
        if (decM == -1)
            continue;

        for (int baseN = 2; baseN <= 36; baseN++)
        {
            long long decN = convert(numN, baseN);
            if (decN == -1)
            {
                continue;
            }

            // printf("Check: %s (base %d) = %s (base %d), decimals: %11d = %11d\n", M, baseM, N, baseN, decM, decN);

            if (decM == decN)
            {
                if (isMNegative && isNNegative)
                {
                    printf("%s (base %d) = %s (base %d)\n", M, baseM, N, baseN);
                }
                else
                {
                    printf("%s (base %d) = %s (base %d)\n", M, baseM, N, baseN);
                }
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("%s is not equal to %s in any base 2..36\n", M, N);
    }
}
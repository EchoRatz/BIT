#include <stdio.h>
int main()
{
    printf("Please Enter the Scores:\n");
    int score, i, max = 0, min = 100, sum = 0;
    for (i = 0; i < 10; i++)
    {

        scanf("%d", &score);
        sum += score;
        if (score > max)
            max = score;
        if (score < min)
            min = score;
    }
    printf("Canceled Max Score:%d\nCanceled Min Score:%d\n", max, min);
    printf("Average Score:%d\n", (sum - max - min) / 8);
}
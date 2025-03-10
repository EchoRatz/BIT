#include <stdio.h>
int main()
{

    int num1, num2, num3;
    char name[20];

    printf("Welcome to Lost Fortune!\n\n");
    printf("Please enter the following for your personalized adventure.\n\n");

    printf("Enter a number:");
    scanf("%d", &num1);
    printf("Enter a number, smaller than the first:");
    scanf("%d", &num2);
    printf("Enter your name:");
    scanf(" %[^\n]", &name);

    printf("\n\n");

    printf("A brave group of %d set out on a quest -- in search of the lost treasure of the Ancient Dwarves.\n", num1);

    printf("The group was led by the legendary rogue, %s\n\n", name);

    printf("Along the way, a band of marauding ogres ambushed the party. All fought bravely under the command of %s, and the ogres were defeated, but at a cost.\n", name);

    num3 = num1 - num2;

    printf("Of the adventurers, %d were vanquished, leaving just %d in the group.\n\n", num2, num3);

    printf("The party was about to give up all hope. But while laying the deceased to rest, they stumbled upon the buried fortune. So the adventurers split 1000 gold pieces. Each got %d gold pieces. %s held on to the extra %d pieces to keep things fair of course.\n", 1000 / (num1 - num2), name, 1000 % (num1 - num2));
}
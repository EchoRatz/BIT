#include <stdio.h>
#include <stdlib.h>

// Structure to represent a dragon
typedef struct {
    int hardness;
    int experience;
} Dragon;

// Comparison function for sorting dragons by their hardness
int compare(const void* a, const void* b) {
    Dragon* dragonA = (Dragon*)a;
    Dragon* dragonB = (Dragon*)b;
    if (dragonA->hardness != dragonB->hardness) {
        return dragonA->hardness - dragonB->hardness;
    }
    return dragonB->experience - dragonA->experience; // If hardness is the same, prefer higher experience
}

int main() {
    int n;
    scanf("%d", &n);

    Dragon dragons[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &dragons[i].hardness, &dragons[i].experience);
    }

    // Sort dragons by hardness, then by experience in descending order
    qsort(dragons, n, sizeof(Dragon), compare);

    long long currentAttackPower = 0;
    long long moneySpent = 0;

    for (int i = 0; i < n; i++) {
        if (currentAttackPower < dragons[i].hardness) {
            moneySpent += dragons[i].hardness - currentAttackPower;
            currentAttackPower = dragons[i].hardness;
        }
        currentAttackPower += dragons[i].experience;
    }

    printf("%lld\n", moneySpent);

    return 0;
}

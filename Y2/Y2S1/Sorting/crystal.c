#include <stdio.h>

void largest_crystal(int num_crystals, int crystals[][3]) {
    long long max_single_vol = 0;
    int max_single_idx = -1;

    long long max_merge_vol = 0;
    int max_merge_indices[2] = {-1, -1};

    for (int i = 0; i < num_crystals; i++) {
        int length = crystals[i][0];
        int width = crystals[i][1];
        int height = crystals[i][2];
        long long volume = (long long)length * width * height;

        if (volume > max_single_vol) {
            max_single_vol = volume;
            max_single_idx = i + 1;
        }
    }

    for (int i = 0; i < num_crystals; i++) {
        for (int j = i + 1; j < num_crystals; j++) {
            int l1 = crystals[i][0], w1 = crystals[i][1], h1 = crystals[i][2];
            int l2 = crystals[j][0], w2 = crystals[j][1], h2 = crystals[j][2];

            if ((l1 == l2 && w1 == w2) || (l1 == w2 && w1 == l2)) {
                long long merged_h = h1 + h2;
                long long merged_vol = (long long)l1 * w1 * merged_h;
                if (merged_vol > max_merge_vol) {
                    max_merge_vol = merged_vol;
                    max_merge_indices[0] = i + 1;
                    max_merge_indices[1] = j + 1;
                }
            }

            if ((l1 == l2 && h1 == h2) || (l1 == h2 && h1 == l2)) {
                long long merged_h = w1 + w2;
                long long merged_vol = (long long)l1 * h1 * merged_h;
                if (merged_vol > max_merge_vol) {
                    max_merge_vol = merged_vol;
                    max_merge_indices[0] = i + 1;
                    max_merge_indices[1] = j + 1;
                }
            }

            if ((w1 == w2 && h1 == h2) || (w1 == h2 && h1 == w2)) {
                long long merged_h = l1 + l2;
                long long merged_vol = (long long)w1 * h1 * merged_h;
                if (merged_vol > max_merge_vol) {
                    max_merge_vol = merged_vol;
                    max_merge_indices[0] = i + 1;
                    max_merge_indices[1] = j + 1;
                }
            }
        }
    }

    if (max_single_vol >= max_merge_vol) {
        printf("1\n");
        printf("%d\n", max_single_idx);
    } else {
        printf("2\n");
        printf("%d %d\n", max_merge_indices[0], max_merge_indices[1]);
    }
}

int main() {
    int num_crystals;

    // Read the number of crystals
    scanf("%d", &num_crystals);

    int crystals[num_crystals][3];

    // Read the dimensions of each crystal
    for (int i = 0; i < num_crystals; i++) {
        scanf("%d %d %d", &crystals[i][0], &crystals[i][1], &crystals[i][2]);
    }

    largest_crystal(num_crystals, crystals);

    return 0;
}

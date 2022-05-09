#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int seg[11][11] = {
        { 0, 4, 3, 3, 4, 3, 2, 2, 1, 2, 6 },
        { 4, 0, 5, 3, 2, 5, 6, 2, 5, 4, 2 },
        { 3, 5, 0, 2, 5, 4, 3, 5, 2, 3, 5 },
        { 3, 3, 2, 0, 3, 2, 3, 3, 2, 1, 5 },
        { 4, 2, 5, 3, 0, 3, 4, 2, 3, 2, 4 },
        { 3, 5, 4, 2, 3, 0, 1, 3, 2, 1, 5 },
        { 2, 6, 3, 3, 4, 1, 0, 4, 1, 2, 6 },
        { 2, 2, 5, 3, 2, 3, 4, 0, 3, 2, 4 },
        { 1, 5, 2, 2, 3, 2, 1, 3, 0, 1, 7 },
        { 2, 4, 3, 1, 2, 1, 2, 2, 1, 0, 6 },
        { 6, 2, 5, 5, 4, 5, 6, 4, 7, 6, 0 }
    };

    int N;
    scanf("%d", &N);

    int* before = (int*)malloc(sizeof(int) * N);
    int* after = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", before + i, after + i);
    }

    int i, j, k;
    int sum, check_before, check_after;
    for (i = 0; i < N; i++) {
        sum = 0;
        check_before = 1;
        check_after = 1;

        j = before[i] / 10000;
        before[i] -= j * 10000;
        if (j == 0 && check_before)
            j += 10;
        else
            check_before = 0;
        k = after[i] / 10000;
        after[i] -= k * 10000;
        if (k == 0 && check_after)
            k += 10;
        else
            check_after = 0;
        sum += seg[j][k];

        j = before[i] / 1000;
        before[i] -= j * 1000;
        if (j == 0 && check_before)
            j += 10;
        else
            check_before = 0;
        k = after[i] / 1000;
        after[i] -= k * 1000;
        if (k == 0 && check_after)
            k += 10;
        else
            check_after = 0;
        sum += seg[j][k];

        j = before[i] / 100;
        before[i] -= j * 100;
        if (j == 0 && check_before)
            j += 10;
        else
            check_before = 0;
        k = after[i] / 100;
        after[i] -= k * 100;
        if (k == 0 && check_after)
            k += 10;
        else
            check_after = 0;
        sum += seg[j][k];

        j = before[i] / 10;
        before[i] -= j * 10;
        if (j == 0 && check_before)
            j += 10;
        else
            check_before = 0;
        k = after[i] / 10;
        after[i] -= k * 10;
        if (k == 0 && check_after)
            k += 10;
        else
            check_after = 0;
        sum += seg[j][k];

        j = before[i];
        k = after[i];
        sum += seg[j][k];

        printf("%d\n", sum);
    }

    free(before);
    free(after);

    return 0;
}

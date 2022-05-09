#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;

    int N;
    scanf("%d", &N);

    int* stones = (int*)malloc(sizeof(int) * N);
    i = 0;
    do {
        scanf("%d", stones + (i++));
    } while (getc(stdin) == ' ');

    int* counts = malloc(sizeof(int) * N);

    for (i = 1; i < N; i++)
        for (j = 0; j < i; j++)
            if (stones[i] > stones[j])
                if (counts[i] < counts[j] + 1)
                    counts[i] = counts[j] + 1;

    int max = counts[0];
    for (i = 1; i < N; i++)
        if (max < counts[i])
            max = counts[i];

    printf("%d", max + 1);

    free(stones);
    free(counts);

    return 0;
}

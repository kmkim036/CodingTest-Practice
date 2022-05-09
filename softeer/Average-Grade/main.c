#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;

    int N, K;
    scanf("%d %d\n", &N, &K);

    int* grade = malloc(sizeof(int) * N);
    i = 0;
    do {
        scanf("%d", &grade[i++]);
    } while (i < N);

    int start, end, sum;
    for (i = 0; i < K; i++) {
        scanf("%d %d\n", &start, &end);
        sum = 0;
        for (j = start - 1; j < end; j++)
            sum += grade[j];
        printf("%.2lf\n", (double)sum / (end - start + 1));
    }

    free(grade);

    return 0;
}
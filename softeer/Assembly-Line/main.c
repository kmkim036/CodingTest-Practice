#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, k;
    int N;
    scanf("%d", &N);

    int** line;
    line = malloc(sizeof(int*) * N);
    for (i = 0; i < N - 1; i++) {
        line[i] = malloc(sizeof(int) * 4);
        scanf("%d %d %d %d\n", &line[i][0], &line[i][1], &line[i][2], &line[i][3]);
    }

    int last[2];
    scanf("%d %d", &last[0], &last[1]);

    int totalA = 0, totalB = 0, nowA = 0, nowB = 0;

    for (i = 0; i < N - 1; i++) {
        if (N == 1)
            break;
        nowA = line[i][0] + totalA;
        if (nowA > line[i][1] + line[i][3] + totalB)
            nowA = line[i][1] + line[i][3] + totalB;
        nowB = line[i][1] + totalB;
        if (nowB > line[i][0] + line[i][2] + totalA)
            nowB = line[i][0] + line[i][2] + totalA;

        totalA = nowA;
        totalB = nowB;
    }

    totalA += last[0];
    totalB += last[1];

    if (totalA < totalB)
        printf("%d", totalA);
    else
        printf("%d", totalB);

    for (i = 0; i < N; i++)
        free(line[i]);
    free(line);

    return 0;
}

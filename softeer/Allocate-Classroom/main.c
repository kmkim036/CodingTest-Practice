#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;

    int counts = 0, timee = 0;

    int N;
    scanf("%d\n", &N);

    int** Schedule = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        Schedule[i] = malloc(sizeof(int) * 2);
        scanf("%d %d", *(Schedule + i) + 0, *(Schedule + i) + 1);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++) {
            if (Schedule[j][0] > Schedule[j + 1][0]) {
                int* temp = *(Schedule + j);
                *(Schedule + j) = *(Schedule + j + 1);
                *(Schedule + j + 1) = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (timee > Schedule[N - 1][0])
            break;
        if (timee <= Schedule[i][0]) {
            counts++;
            timee = Schedule[i][1];
        }
    }

    printf("%d", counts);
    free(Schedule);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;

    int counts = 0, timee = 0;

    int N;
    scanf("%d\n", &N);

    int** Schedule = malloc(sizeof(int*) * N);
    for (i = 0; i < N; i++) {
        Schedule[i] = malloc(sizeof(int) * 2);
        scanf("%d %d", *(Schedule + i) + 0, *(Schedule + i) + 1);
    }

    char swap;
    int* temp;
    for (i = 0; i < N; i++) {
        swap = 'N';
        for (j = 0; j < N - 1; j++) {
            if (Schedule[j][0] > Schedule[j + 1][0]) {
                temp = *(Schedule + j);
                *(Schedule + j) = *(Schedule + j + 1);
                *(Schedule + j + 1) = temp;
                swap = 'Y';
            }
        }
        if (swap == 'N')
            break;
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

    for (i = 0; i < N; i++)
        free(Schedule[i]);
    free(Schedule);

    return 0;
}

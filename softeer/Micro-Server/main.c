#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 900

int compare(int* a, int* b) // 오름차순 비교 함수 구현
{
    return *b - *a;
}

int main(void)
{
    int T;
    scanf("%d", &T);

    int repeat, i, j, sum, cnts;
    for (repeat = 0; repeat < T; repeat++) {
        int N;
        scanf("%d", &N);

        int* arr = (int*)malloc(sizeof(int) * N);
        i = 0;
        do {
            scanf("%d", arr + i);
            i++;
        } while (getc(stdin) == ' ');

        qsort(arr, N, sizeof(int), compare);

        cnts = 0;
        for (i = 0; i < N; i++) {
            if (arr[i] == 0)
                continue;

            sum = arr[i];

            for (j = i + 1; j < N; j++) {
                if (sum + arr[N - 1] > 900)
                    break;
                if (arr[j] == 0)
                    continue;
                if (sum + arr[j] <= THRESHOLD) {
                    sum += arr[j];
                    arr[j] = 0;
                }
            }
            cnts++;
        }
        printf("%d\n", cnts);
        free(arr);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;
    int i = 0, j;
    scanf("%d %d ", &N, &K);

    int* arr = (int*)malloc(sizeof(int) * N);
    do {
        scanf("%d", arr + (i++));
    } while (getc(stdin) == ' ');

    int* start = (int*)malloc(sizeof(int) * K);
    int* end = (int*)malloc(sizeof(int) * K);
    for (i = 0; i < K; i++) {
        scanf("%d %d", start + i, end + i);
    }

    for (i = 0; i < K; i++) {
        int sum = 0;
        for (j = start[i]; j <= end[i]; j++) {
            sum += arr[j - 1];
        }
        printf("%.2lf\n", ((double)sum / (end[i] - start[i] + 1)));
    }

    free(arr);
    free(start);
    free(end);

    return 0;
}

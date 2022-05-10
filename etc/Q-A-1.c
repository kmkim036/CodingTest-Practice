#include <stdio.h>
#include <stdlib.h>

// 단순하게 이중 for문을 통해 매번 합을 구하는 것이 아닌
// 기존에 구해놓은 합을 활용하여 단일 for문을 통해 구현하는 것이 관건

int main()
{
    int i, j;

    int N, K;
    scanf("%d %d", &N, &K);

    int* arr = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
        scanf("%d", arr + i);

    int sum = 0;

    for (i = 0; i < K; i++)
        sum += arr[i];

    int min = sum;
    for (i = 0; i < N - K; i++) {
        sum -= arr[i];
        sum += arr[i + K];
        if (sum < min)
            min = sum;
    }

    /*
    // 아쉬운 풀이
    int sum, min = 0xFFFE;
    for (i = 0; i < N - K + 1; i++) {
        sum = 0;
        for (j = i; j < i + K; j++)
            sum += arr[j];
        if (sum < min)
            min = sum;
    }
    */

    printf("%d\n", min);

    free(arr);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;

    int N, M;
    scanf("%d %d\n", &N, &M);

    int* Weight = (int*)malloc(sizeof(int) * N);
    int* check = (int*)malloc(sizeof(int) * N);

    int cnts = N;
    for (i = 0; i < N; i++)
        scanf("%d ", &Weight[i]);

    int a, b;
    for (i = 0; i < M; i++) {
        scanf("%d %d\n", &a, &b);
        if (!check[a - 1])
            if (Weight[a - 1] <= Weight[b - 1]) {
                check[a - 1] = 1;
                cnts--;
            }
        if (!check[b - 1])
            if (Weight[b - 1] <= Weight[a - 1]) {
                check[b - 1] = 1;
                cnts--;
            }
    }

    printf("%d", cnts);

    free(Weight);
    free(check);

    return 0;
}

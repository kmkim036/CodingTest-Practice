#include <stdio.h>
#include <stdlib.h>

int min = 0xFFFE;
int* rail;
int N, M, K;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void check_sum()
{
    int i, j, k;
    int idx = 0, sum = 0;

    for (i = 0; i < K; i++) {
        int bag = rail[idx];
        while (bag + rail[(idx + 1) % N] <= M) {
            idx = (idx + 1) % N;
            bag += rail[idx];
        }
        idx = (idx + 1) % N;
        sum += bag;
    }

    if (min > sum)
        min = sum;
}

void permutation(int n, int r, int depth)
{
    int i;
    if (r == depth) {
        check_sum();
        return;
    }
    for (i = depth; i < n; i++) {
        swap(&rail[i], &rail[depth]);
        permutation(n, r, depth + 1);
        swap(&rail[i], &rail[depth]);
    }
}

int main(void)
{
    scanf("%d %d %d\n", &N, &M, &K);
    rail = malloc(sizeof(int) * N);

    int i, j, k;
    for (i = 0; i < N; i++)
        scanf("%d ", &rail[i]);

    permutation(N, N, 0);

    printf("%d\n", min);

    free(rail);

    return 0;
}

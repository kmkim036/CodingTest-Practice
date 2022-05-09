#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M, K;
    scanf("%d %d %d\n", &N, &M, &K);

    int* A = malloc(sizeof(int) * N);
    int* B = malloc(sizeof(int) * M);
    int** C = malloc(sizeof(int*) * N);

    int i, j, max = 0;

    for (i = 0; i < N; i++)
        C[i] = malloc(sizeof(int) * M);
    for (i = 0; i < N; i++)
        scanf("%d ", A + i);
    for (i = 0; i < M; i++)
        scanf("%d ", B + i);

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (A[i] == B[j]) {
                if (i == 0 || j == 0)
                    C[i][j] = 1;
                else
                    C[i][j] = C[i - 1][j - 1] + 1;
                if (max < C[i][j])
                    max = C[i][j];
            }
        }
    }

    printf("%d", max);

    free(A);
    free(B);
    free(C);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;
    int N, M;
    scanf("%d %d", &N, &M);

    int* Real_Range = (int*)malloc(sizeof(int) * (1 + N));
    int* Real_Velocity = (int*)malloc(sizeof(int) * N);
    int* Test_Range = (int*)malloc(sizeof(int) * (1 + M));
    int* Test_Velocity = (int*)malloc(sizeof(int) * M);

    int sum = 0;
    Real_Range[0] = 0;
    for (i = 0; i < N; i++) {
        scanf("%d %d\n", Real_Range + (1 + i), Real_Velocity + i);
        Real_Range[i + 1] += sum;
        sum = Real_Range[i + 1];
    }
    sum = 0;
    Test_Range[0] = 0;
    for (i = 0; i < M; i++) {
        scanf("%d %d\n", Test_Range + (i + 1), Test_Velocity + i);
        Test_Range[i + 1] += sum;
        sum = Test_Range[i + 1];
    }

    int max = 0;
    int sub;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (Test_Range[i] >= Real_Range[j + 1] || Test_Range[i + 1] <= Real_Range[j])
                continue;
            if (Test_Velocity[i] > Real_Velocity[j]) {
                sub = Test_Velocity[i] - Real_Velocity[j];
                if (max < sub)
                    max = sub;
            }
        }
    }

    printf("%d", max);

    free(Real_Range);
    free(Real_Velocity);
    free(Test_Range);
    free(Test_Velocity);

    return 0;
}

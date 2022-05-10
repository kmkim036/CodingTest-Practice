#include <stdio.h>
#include <stdlib.h>

// 어떻게 cost를 가장 적게 가져갈까
// a의 순서를 바꾸는 과정에서 b가 같은 경우는 필연적으로 생긴다.
// 이외의 불필요한 swap이 없도록 해야 한다.
// 최적화된 버블정렬을 사용하자

int main()
{
    int i, j;
    int N;
    scanf("%d", &N);

    int* a = malloc(sizeof(int) * N);
    int* b = malloc(sizeof(int) * N);

    for (i = 0; i < N; i++)
        scanf("%d", a + i);

    for (i = 0; i < N; i++)
        scanf("%d", b + i);

    char swap;
    int temp;
    int cost = 0;

    for (i = 1; i < N; i++) {
        swap = 'N';
        for (j = 0; j < N - i; j++) {
            if (a[j] > a[j + 1]) {
                if (b[j] == b[j + 1])
                    cost++;

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                swap = 'Y';
            }
        }
        if (swap == 'N')
            break;
    }

    printf("%d\n", cost);

    return 0;
}
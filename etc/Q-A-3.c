#include <stdio.h>
#include <stdlib.h>

// Q: 각 node color 별로 하나 이상의 해당 node color를 지나는 단순 경로의 수를 구하라
// 중복은 제외

/*
example
총 3개의 node가 있고, color와 edge는 다음과 같다.
1 - 2 - 1
1번 color: 1(왼쪽 node), 1 - 2, 1 - 2 - 1, 2 - 1, 1(오른쪽 node)
2번 color: 1 - 2, 2, 2 - 1
3번 color: x
output: 
5
3
0
*/

// 조합(combination)을 이용해보자
// nC1 ~ nCn-1을 돌려보면서 각 경우에 대해 아래의 조건을 확인
// 1) node를 잇는 edge가 있는가
// 2) 찾고 있는 color의 node가 존재하는가

int N;
int* node_color;
int** edge;

int main()
{
    int i, j;

    scanf("%d", &N);

    *node_color = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
        scanf("%d", node_color + i);

    edge = malloc(sizeof(int*) * (N - 1));
    for (i = 0; i < N - 1; i++) {
        edge[i] = malloc(sizeof(int) * 2);
        scanf("%d %d", *(edge + i), *(edge + i) + 1);
    }

    for (i = 0; i < N - 1; i++) {
        int ret;
        // ret = function(i);
        printf("%d\n", ret);
    }

    free(node_color);
    for (i = 0; i < N - 1; i++)
        free(edge[i]);

    return 0;
}
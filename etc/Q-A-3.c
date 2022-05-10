#include <stdio.h>
#include <stdlib.h>

// 각 node color 별로 하나 이상의 해당 node color를 지나는 단순 경로의 수를 구하라

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

int main()
{
    int i, j;

    int N;
    scanf("%d", &N);

    int *node_color = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
        scanf("%d", node_color + i);
    
    int **edge = malloc(sizeof(int *) * (N-1));
    for (i = 0; i < N-1; i++) {
        edge[i] = malloc(sizeof(int) * 2);
        scanf("%d %d", *(edge + i), *(edge + i )+  1);
    }

}
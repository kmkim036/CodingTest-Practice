#include <stdio.h>

int** arr;
int H, W;

void color(int a, int b, int c)
{
    int oldc = arr[a][b];
    arr[a][b] = c;

    if (a > 0 && oldc == arr[a - 1][b])
        color(a - 1, b, c);
    if (a < H - 1 && oldc == arr[a + 1][b])
        color(a + 1, b, c);
    if (b > 0 && oldc == arr[a][b - 1])
        color(a, b - 1, c);
    if (b < W - 1 && oldc == arr[a][b + 1])
        color(a, b + 1, c);

    return;
}

int main(void)
{
    int i, j;
    scanf("%d %d\n", &H, &W);

    arr = malloc(sizeof(int*) * H);
    for (i = 0; i < H; i++) {
        arr[i] = malloc(sizeof(int) * W);
        for (j = 0; j < W; j++)
            scanf("%d ", *(arr + i) + j);
    }

    int Q;
    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (arr[a - 1][b - 1] != c)
            color(a - 1, b - 1, c);
    }

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

	free(arr);
	
    return 0;
}

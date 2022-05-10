#include <stdio.h>
#include <stdlib.h>

int** arr;
int W, H;

// dir: 1 ^
// dir: 2 >
// dir: 3 v
// dir: 4 <

void move(int i, int j, int dir)
{
    arr[i][j] = 0;
    if (dir == 0) {
        if (arr[i - 1][j]) {
            printf("^\nA");
            dir = 1;
            arr[i - 1][j] = 0;
            move(i - 2, j, dir);
        } else if (arr[i][j + 1]) {
            printf(">\nA");
            dir = 2;
            arr[i][j + 1] = 0;
            move(i, j + 2, dir);
        } else if (arr[i + 1][j]) {
            printf("v\nA");
            dir = 3;
            arr[i + 1][j] = 0;
            move(i + 2, j, dir);
        } else if (arr[i][j - 1]) {
            printf("<\nA");
            dir = 4;
            arr[i][j - 1] = 0;
            move(i, j - 2, dir);
        }
    } else {
        if (arr[i - 1][j]) {
            if (dir == 1) {
            } else if (dir == 2) {
                printf("L");
            } else if (dir == 3) {
            } else if (dir == 4) {
                printf("R");
            }
            printf("A");
            dir = 1;
            arr[i - 1][j] = 0;
            move(i - 2, j, dir);
        } else if (arr[i][j + 1]) {
            if (dir == 1) {
                printf("R");
            } else if (dir == 2) {
            } else if (dir == 3) {
                printf("L");
            } else if (dir == 4) {
            }
            printf("A");
            dir = 2;
            arr[i][j + 1] = 0;
            move(i, j + 2, dir);
        } else if (arr[i + 1][j]) {
            if (dir == 1) {
            } else if (dir == 2) {
                printf("R");
            } else if (dir == 3) {
            } else if (dir == 4) {
                printf("L");
            }
            printf("A");
            dir = 3;
            arr[i + 1][j] = 0;
            move(i + 2, j, dir);
        } else if (arr[i][j - 1]) {
            if (dir == 1) {
                printf("L");
            } else if (dir == 2) {
            } else if (dir == 3) {
                printf("R");
            } else if (dir == 4) {
            }
            printf("A");
            dir = 4;
            arr[i][j - 1] = 0;
            move(i, j - 2, dir);
        } else
            return;
    }
}

int main(void)
{
    int i, j, k;
    scanf("%d %d\n", &H, &W);
    arr = malloc(sizeof(int*) * (2 + H));
    for (i = 0; i < 2 + H; i++)
        arr[i] = malloc(sizeof(int) * (2 + W));

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            char c;
            scanf("%c\n", &c);
            if (c == '#')
                arr[i + 1][j + 1] = 1;
            else
                arr[i + 1][j + 1] = 0;
        }
    }

    int sum = 0;
    for (i = 1; i < H + 2; i++) {
        for (j = 1; j < W + 2; j++) {
            if (arr[i][j]) {
                sum = arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1];
                if (sum == 1)
                    break;
            }
        }
        if (sum == 1)
            break;
    }

    printf("%d %d\n", i, j);
    move(i, j, 0);

    for (i = 0; i < 2 + H; i++)
        free(arr[i]);
    free(arr);

    return 0;
}

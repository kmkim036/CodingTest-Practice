#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;

    int N, K;
    scanf("%d %d ", &N, &K);

    char* str;
    str = (char*)malloc(sizeof(char) * (N));
    for (i = 0; i < N; i++)
        scanf("%c", str + i);

    int counts = 0;
    for (i = 0; i < N; i++) {
        if (str[i] == 'H' || str[i] == 'A')
            continue;
        for (j = i - K; j <= i + K; j++) {
            if (j < 0 || j == i)
                continue;
            if (str[j] == 'H') {
                counts++;
                str[j] = 'A';
                break;
            }
        }
    }
    printf("%d", counts);

    free(str);

    return 0;
}

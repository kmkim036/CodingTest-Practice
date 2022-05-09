#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;
    int M, N, K;

    scanf("%d %d %d", &M, &N, &K);
    if (M > N) {
        printf("normal");
        return 0;
    }

    int* secret = (int*)malloc(sizeof(int) * M);
    int* user = (int*)malloc(sizeof(int) * N);
    for (i = 0; i < M; i++)
        scanf("%d", secret + i);
    for (i = 0; i < N; i++)
        scanf("%d", user + i);

    for (i = 0; i < N + 1 - M; i++) {
        for (j = 0; j < M; j++) {
            if (secret[j] == user[j + i])
                continue;
            else
                break;
        }
        if (j == M)
            break;
    }
    if (j == M)
        printf("secret");
    else
        printf("normal");
    
	free(secret);
	free(user);
	
	return 0;
}

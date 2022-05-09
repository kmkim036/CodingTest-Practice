#include <stdio.h>

int main(void)
{
    long long K, N, P, mod = 1000000007;
    scanf("%lld %lld %lld", &K, &P, &N);

    int i;
    for (i = 0; i < N; i++)
        K = (K * P) % mod;
    
	printf("%d", K);
    
	return 0;
}

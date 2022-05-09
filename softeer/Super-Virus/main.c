#include <stdio.h>

long long mod = 1000000007;
long long K, N, P;

long long multiply(long long n)
{
    if (n == 1)
        return P % mod;
    else {
        long long ret = multiply(n / 2);
        ret = (ret * ret) % mod;
        if (n % 2)
            ret = (ret * P) % mod;
        return ret;
    }
}

int main(void)
{
    scanf("%lld %lld %lld", &K, &P, &N);

    N *= 10;
    long long ret = multiply(N);

    printf("%d", (K * ret) % mod);

    return 0;
}

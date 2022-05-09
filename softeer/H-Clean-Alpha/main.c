#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long P, N; 
	scanf("%lld %lld\n", &P, &N);
	long long sum = 0;
	long long input;

	int i;
	for(i = 0; i < N; i++){
		scanf("%lld ", &input);
		sum = (sum * P + input) % 1000000007;
	}

	printf("%lld\n", sum);
	
	return 0;
}

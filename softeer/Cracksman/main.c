#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int N, Bag;
    scanf("%d %d\n", &Bag, &N);

    int* Weight = (int*)malloc(sizeof(int) * N);
    int* Price = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d %d\n", Weight + i, Price + i);

    int sum_weight = 0, sum_price = 0;
    int max, idx;
    while (1) {
        max = 0;
        for (i = 0; i < N; i++) {
            if (Price[i] > max) {
                max = Price[i];
                idx = i;
            }
        }
        if (sum_weight + Weight[idx] <= Bag) {
            sum_weight += Weight[idx];
            sum_price += Weight[idx] * Price[idx];
            Price[idx] = 0;
        } else {
            sum_price += Price[idx] * (Bag - sum_weight);
            break;
        }
    }

    free(Weight);
    free(Price);

    printf("%d", sum_price);

    return 0;
}

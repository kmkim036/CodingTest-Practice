#include <stdio.h>

int main(void)
{
    int num[8];
    scanf("%d %d %d %d %d %d %d %d ", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7]);

    if (num[0] == 1 && num[1] == 2 && num[2] == 3 && num[3] == 4 && num[4] == 5 && num[5] == 6 && num[6] == 7 && num[7] == 8)
        printf("ascending ");
    else if (num[7] == 1 && num[6] == 2 && num[5] == 3 && num[4] == 4 && num[3] == 5 && num[2] == 6 && num[1] == 7 && num[0] == 8)
        printf("descending ");
    else
        printf("mixed ");

    return 0;
}

#include <stdio.h>

int main(void)
{
    int num, i;
    scanf("%d", &num);

    int points = 1;
    for (i = 0; i < num; i++)
        points *= 2;
    
    points += 1;
    printf("%d", points * points);
    
    return 0;
}

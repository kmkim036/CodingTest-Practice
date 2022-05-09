#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i, j, k;

    int N, Meetings;
    scanf("%d %d\n", &N, &Meetings);

    char** Name = malloc(sizeof(char*) * N);
    for (i = 0; i < N; i++) {
        Name[i] = malloc(sizeof(char) * 30);
        scanf("%s\n", Name[i]);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++) {
            if (strcmp(Name[j], Name[j + 1]) > 0) {
                char tmp[30];
                strcpy(tmp, Name[j]);
                strcpy(Name[j], Name[j + 1]);
                strcpy(Name[j + 1], tmp);
            }
        }
    }

    int** time_table;
    time_table = malloc(sizeof(int*) * N);
    for (i = 0; i < N; i++) {
        time_table[i] = malloc(sizeof(int) * 9);
    }

    for (i = 0; i < Meetings; i++) {
        char str[30];
        int a, b, c;
        scanf("%s %d %d\n", str, &a, &b);
        for (j = 0; j < N; j++)
            if (strcmp(str, Name[j]) == 0) {
                c = j;
                break;
            }
        a -= 9;
        b -= 9;
        for (k = a; k < b; k++)
            time_table[c][k] = 1;
    }

    int start_time, end_time;
    for (i = 0; i < N; i++) {
        int available_cnts = 0;
        int printtable[10][2] = {
            0,
        };
        for (j = 0; j < 9; j++) {
            if (time_table[i][j] == 0) {
                start_time = j + 9;
                while (time_table[i][j + 1] == 0 && j < 8) {
                    time_table[i][j] = 1;
                    j++;
                }
                end_time = j + 10;
                printtable[available_cnts][0] = start_time;
                printtable[available_cnts][1] = end_time;
                available_cnts++;
            }
        }
        printf("Room %s:\n", Name[i]);
        if (available_cnts == 0)
            printf("Not available\n");
        else {
            printf("%d available:\n", available_cnts);
            for (k = 0; k < available_cnts; k++)
                printf("%02d-%02d\n", printtable[k][0], printtable[k][1]);
        }
        if (i != N - 1)
            printf("-----\n");
    }

    for (i = 0; i < N; i++)
        free(Name[i]);
    free(Name);

    for (i = 0; i < N; i++)
        free(time_table[i]);
    free(time_table);

    return 0;
}

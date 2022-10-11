#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define IP_SIZE 100000

int main()
{
    FILE *fp;
    int i;

    fp = fopen("./ip_stream.txt", "w+");
    if (fp == NULL)
    {
        printf("failed to open file\n");
        return 1;
    }

    srand(2532);

    for (i = 0; i < IP_SIZE; i++)
    {
        fprintf(fp, "%d.%d.%d.%d\n", rand() % (int)pow(2, 8), rand() % (int)pow(2, 8), rand() % (int)pow(2, 8), rand() % (int)pow(2, 8));
    }

    fclose(fp);

    return 0;
}
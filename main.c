#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "zeros.h"
#include "sort.h"


#define SEED 7878696











int main()
{
    FILE *fp = NULL;
    IP_ADDR ip_addr, ip_addr_1, ip_addr_2, ip_addr_3, ip_addr_4;
    int max_zeros = 0;
    int ntimes, i;
    int a1, a2, a3, a4, b1, b2, b3, b4;

    // a and b are random coefficients of hash function
    IP_ADDR a, b;

    int *max_zeros_arr;

    printf("How many times should the program run?\n");
    scanf("%d", &ntimes);

    max_zeros_arr = malloc(ntimes * sizeof(int));

    srand(SEED);

    for (i = 0; i < ntimes; i++)
    {
        a1 = rand() % (int)(pow(2, 8));
        a2 = rand() % (int)(pow(2, 8));
        a3 = rand() % (int)(pow(2, 8));
        a4 = rand() % (int)(pow(2, 8));
        a = a1 * pow(2, 24) + a2 * pow(2, 16) + a3 * pow(2, 8) + a4;

        b1 = rand() % (int)(pow(2, 8));
        b2 = rand() % (int)(pow(2, 8));
        b3 = rand() % (int)(pow(2, 8));
        b4 = rand() % (int)(pow(2, 8));
        b = b1 * pow(2, 24) + b2 * pow(2, 16) + b3 * pow(2, 8) + b4;

        fp = fopen("./ip_stream.txt", "r");
        if (fp == NULL)
        {
            printf("failed to open file\n");
            return 1;
        }
        while ((fscanf(fp, "%d.%d.%d.%d", &ip_addr_1, &ip_addr_2, &ip_addr_3, &ip_addr_4)) != EOF)
        {
            ip_addr = ip_addr_1 * pow(2, 24) + ip_addr_2 * pow(2, 16) + ip_addr_3 * pow(2, 8) + ip_addr_4;
            distinct_elements(ip_addr, &max_zeros, a, b);
        }
        max_zeros_arr[i] = max_zeros;
        fclose(fp);
    }
    sort(max_zeros_arr, ntimes);
    max_zeros = max_zeros_arr[(ntimes+1) / 2 - 1];
    printf("Estimated number of distinct ip address: %f", pow(2, max_zeros + 0.5));
    return 0;
}
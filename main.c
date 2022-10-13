#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define IP_ADDR unsigned int
#define SEED 7878696

// a and b are random coefficients of hash function
IP_ADDR a;
IP_ADDR b;

IP_ADDR hash(IP_ADDR ip_addr)
{
    // return the hash value of ip_addr
    long long int value;
    value = (ip_addr * a + b) % (long long int)(pow(2, 32));
    return (IP_ADDR)value;
}

int zeros(IP_ADDR hash_value)
{
    // return the number of rightmost zeros of a hash_value
    int zeros = 0;
    int flag;
    do
    {
        flag = (hash_value >> zeros) & 1;
        zeros++;
    } while (flag == 0);
    return zeros;
}

void distinct_elements(IP_ADDR ip_addr, int *max_zeros)
{
    // update the value of max_zeros
    int z = zeros(hash(ip_addr));
    if (zeros(hash(ip_addr)) > *max_zeros)
        *max_zeros = z;
    return;
}

void swap(int *p, int *q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;
}

void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}

int main()
{
    FILE *fp = NULL;
    IP_ADDR ip_addr, ip_addr_1, ip_addr_2, ip_addr_3, ip_addr_4;
    int max_zeros = 0;
    int ntimes, i;
    int a1, a2, a3, a4, b1, b2, b3, b4;

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
            distinct_elements(ip_addr, &max_zeros);
        }
        max_zeros_arr[i] = max_zeros;
        fclose(fp);
    }
    sort(max_zeros_arr, ntimes);
    max_zeros = max_zeros_arr[(ntimes+1) / 2 - 1];
    printf("Estimated number of distinct ip address: %f", pow(2, max_zeros + 0.5));
    return 0;
}
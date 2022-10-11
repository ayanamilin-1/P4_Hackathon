#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IP_ADDR unsigned int

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

int main()
{
    FILE *fp = NULL;
    IP_ADDR ip_addr, ip_addr_1, ip_addr_2, ip_addr_3, ip_addr_4;
    int max_zeros = 0;
    
    srand(178232);

    int a1 = rand() % (int)(pow(2, 8));
    int a2 = rand() % (int)(pow(2, 8));
    int a3 = rand() % (int)(pow(2, 8));
    int a4 = rand() % (int)(pow(2, 8));
    a = a1 * pow(2, 11) + a2 * pow(2, 7) + a3 * pow(2, 3) + a4;

    int b1 = rand() % (int)(pow(2, 8));
    int b2 = rand() % (int)(pow(2, 8));
    int b3 = rand() % (int)(pow(2, 8));
    int b4 = rand() % (int)(pow(2, 8));
    b = b1 * pow(2, 11) + b2 * pow(2, 7) + b3 * pow(2, 3) + b4;

    fp = fopen("./ip_stream.txt", "r");
    if (fp==NULL) 
    {
        printf("failed to open file\n");
        return 1;
    }
    while ((fscanf(fp, "%d.%d.%d.%d", &ip_addr_1, &ip_addr_2, &ip_addr_3, &ip_addr_4)) != EOF)
    {
        ip_addr = ip_addr_1 * pow(2, 11) + ip_addr_2 * pow(2, 7) + ip_addr_3 * pow(2, 3) + ip_addr_4;
        distinct_elements(ip_addr, &max_zeros);
    }
    fclose(fp);
    printf("Estimated number of distinct ip address: %f", pow(2, max_zeros + 0.5));
    return 0;
}
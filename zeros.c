#include "zeros.h"
#include <math.h>

IP_ADDR hash(IP_ADDR ip_addr, IP_ADDR a, IP_ADDR b)
{
    // return the hash value of ip_addr
    // a and b are random coefficients of hash function
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

void distinct_elements(IP_ADDR ip_addr, int *max_zeros, IP_ADDR a, IP_ADDR b)
{
    // update the value of *max_zeros
    int z = zeros(hash(ip_addr, a, b));
    if (zeros(hash(ip_addr, a, b)) > *max_zeros)
        *max_zeros = z;
    return;
}
#include "random.h"
#include <stdlib.h>
#include <math.h>



IP_ADDR binary_ip_convert(int binary_ip[])
{
    int i;
    IP_ADDR ip = 0;
    for (i = 31; i >= 0; i--)
    {
        ip += binary_ip[i] * pow(2, 31 - i);
    }
    return ip;
}

IP_ADDR random_ip(unsigned int seed)
{
    int binary_ip[32];
    int i;
    srand(seed);
    for (i = 0; i < 32; i++)
    {
        binary_ip[i] = rand() % 2;
    }
    return (binary_ip_convert(binary_ip));
}

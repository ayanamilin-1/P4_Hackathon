#ifndef ZEROS_H
#define ZEROS_H

#define IP_ADDR unsigned int

IP_ADDR hash(IP_ADDR ip_addr, IP_ADDR a, IP_ADDR b);

int zeros(IP_ADDR hash_value);

void distinct_elements(IP_ADDR ip_addr, int *max_zeros, IP_ADDR a, IP_ADDR b);

#endif
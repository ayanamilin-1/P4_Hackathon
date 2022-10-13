#include "sort.h"

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
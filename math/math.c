#include "math.h"
long long pow(long long num, long long pow)
{
    long long res = 1;
    for (int i = 0; i < pow; i++)
    {
        res *= num;
    }
    return res;
}

double powf(double num, int pow)
{
    long res = 1;
    for (int i = 0; i < pow; i++)
    {
        res *= num;
    }
    return res;
}
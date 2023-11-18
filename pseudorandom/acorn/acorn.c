#include "../../io/out.h"
#include "../../mem/al.h"

float acorn()
{
    const int k = 10;
    unsigned long long Y0n[k] = {23309269401,
                                 72132616601,
                                 83117915661,
                                 90696974041,
                                 20930630369,
                                 61993153921,
                                 59258624043,
                                 35225911873,
                                 51161400979,
                                 78906399143};
    int iPowM = 60;

    unsigned long long M = 0;
    for (int _ = 0; _ < iPowM; _++)
        M += 2 * M;
    unsigned long long Y[k][k];
    for (int i = 0; i < k; i++)
    {
        Y[0][i] = Y0n[i];
    }
    for (int i = 1; i < k; i++)
    {
        Y[i][0] = Y[0][0];
        for (int j = 1; j < k; j++)
        {
            Y[i][j] = (Y[i - 1][j] + Y[i][j - 1]) % M;
        }
    }
    return Y[k - 1][k - 1] / M;
}

int main()
{
    int *a = (int *)malloc(sizeof(int));
    *a = 69;
    free(a);
    acorn() * 1000;
    print("l");
    return 0;
}
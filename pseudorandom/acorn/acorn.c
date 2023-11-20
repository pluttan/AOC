#include "../../io/out.h"
#include "../../mem/al.h"
#include "../../math/math.h"
#include "../../list/string/string.h"

float acorn(const int k, unsigned long long *Y0n, int iPowM)
{
    unsigned long long M = pow(2, iPowM);
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
    iprint(Y[k - 1][k - 1]);
    print("\n");
    long double res = (long double)Y[k - 1][k - 1] / (long double)M;
    fprintR(res, 5);
    print("\n");
    return (long double)Y[k - 1][k - 1] / M;
}

int main()
{
    int *a = (int *)malloc(sizeof(int));
    *a = 69;
    free(a);
    const int k = 2000;
    unsigned long long Y0n[k] = {8333461453744879,
                                 6841363015229961,
                                 10240774981256487,
                                 11468173872453257,
                                 7228610224952711,
                                 8435007367160269,
                                 8834103693589409,
                                 10503658288156691,
                                 6230685553014661,
                                 11153156816412731};
    float out = acorn(k, Y0n, 50);
    fprint(out);
    return 0;
}
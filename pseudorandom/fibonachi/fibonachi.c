#include "../../io/out.h"
#include "../../mem/al.h"
#include "../../math/math.h"
#include "../../list/string/string.h"
#include "../../list/lint/lint.h"

float fibonachi(const int n, lint arr, int powM)
{
    lint tail = litoTail(arr);
    long long M = pow(2, powM);
    for (int i = 55; i < n; i++)
    {
        tail = liadd(tail, ((*lii(arr, i - 24)).this + (*lii(arr, i - 55)).this) % M);
    }
    return (long double)(*tail).this / (long double)M;
}

int main()
{
}
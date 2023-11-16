#include "out.h"

void print(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    asm volatile(
        "mov x0, %0\n"
        "mov x1, %1\n"
        "mov x2, %2\n"
        "mov x16, %3\n"
        "svc 0x80\n"
        :
        : "r"(1), "r"(str), "r"(len), "r"(0x2000004)
        : "x0", "x1", "x2", "x16");
}

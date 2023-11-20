#include <stdio.h>
#include <inttypes.h>

// Определение собственного макроса для формата вывода uint64_t
#define MY_PRIu64 PRIu64

int main()
{
    uint64_t result;

    asm volatile(
        "mov x8, %1\n"         // syscall number for gettimeofday on ARM64
        "mov x0, xzr\n"        // x0 should be 0 for the time system call
        "mov x1, xzr\n"        // x1 should be 0 for the time system call
        "svc 0\n"              // make the system call
        "mov %0, x0\n"         // store the result in the variable 'result'
        : "=r"(result)         // output operand
        : "I"(169)             // syscall number for gettimeofday
        : "x0", "x1", "memory" // clobbered registers and memory
    );

    // Print the result using the custom macro MY_PRIu64
    printf("Current time: %" MY_PRIu64 "\n", result);

    return 0;
}

// viết macro tính tổng nhiều số 

#include <stdio.h>
#include <stdarg.h>

int SUM(int num_args, ...) {
    va_list args;
    va_start(args, num_args);
    int sum = 0;
    for (int i = 0; i < num_args; ++i) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int main() {
    int result = SUM(5, 1, 2, 3, 4, 5);
    printf("Tổng là: %d\n", result);
    return 0;
}
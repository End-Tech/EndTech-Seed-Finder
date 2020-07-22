#include "main.h"

int main()
{

    initGeneration();

    clock_t begin = clock();
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    
    return 0;
}
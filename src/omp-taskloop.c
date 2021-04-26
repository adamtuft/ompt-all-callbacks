#include <omp.h>
#include <stdio.h>

#define LENGTH 5

int main(void)
{
    int nums[LENGTH] = {0}, k = 0;
    #pragma omp parallel num_threads(4)
    #pragma omp single
    #pragma omp taskloop
    for (k=0; k<LENGTH; k++)
    {
        nums[k] = omp_get_thread_num();
    }

    return 0;
}

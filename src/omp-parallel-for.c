#include <omp.h>
#include <stdio.h>

#define LENGTH 30

int main(void)
{
    int nums[LENGTH] = {0}, k = 0;
    #pragma omp parallel num_threads(4)
    #pragma omp for
    for (k=0; k<LENGTH; k++)
    {
        nums[k] = omp_get_thread_num();
    }

    return 0;
}

#include <omp.h>
#include <stdio.h>

#define LENGTH 5

int main(void)
{
    int nums[LENGTH] = {0}, k = 0;
    #pragma omp teams num_teams(3)
    #pragma omp distribute
    for (k=0; k<LENGTH; k++)
    {
        nums[k] = omp_get_thread_num();
    }

    return 0;
}

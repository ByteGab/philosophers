#include <sys/time.h>
#include <stdio.h>

int main (void)
{
    struct timeval current_time;
    gettimeofday(&current_time,NULL);
    printf("segundos: %ld\nmicro segundos: %ld\n",current_time.tv_sec, current_time.tv_usec);
    return (0);
}
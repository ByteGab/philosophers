#include <unistd.h>
#include <stdio.h>

int main (void)
{
    printf("Duerme 20 segundos\n");
    usleep(20000000);
    printf("Desperto!!\n");
    return (0);
}

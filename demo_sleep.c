#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("Duerme 20 segundos\n");
	usleep(20000000);
	printf("Desperto!!\n");
	return (0);
}

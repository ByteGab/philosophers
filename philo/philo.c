#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 5)
		printf("%s\n", "Cuatros argumentos");
	else if (argc == 6)
		printf("%s\n", "Cinco argumentos");
	else
		printf("Error\n");
	return (0);
}
// cambiar segundos a micro
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    if (argc == 0)
        printf("Error\n");
    else
        printf("%d\n",(argc - 1));
    return (0);
}
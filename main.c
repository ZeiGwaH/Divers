#include <stdio.h>
#include <stdlib.h>

int
calculate (int a, int b, char op)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        default:
	    fprintf(stderr, "Argument invalide.\n");
	    exit(EXIT_FAILURE);
    }
}

int
main (int ac, char **av)
{
    if(ac != 4)
    {
	fprintf(stderr, "Liste des arguments invalide.\n");
	return EXIT_FAILURE;
    }
    printf("%d\n", calculate(atoi(av[1]), atoi(av[3]), av[2][0]));
    return EXIT_SUCCESS;
}

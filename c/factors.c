#include "factors.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument values
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: factors <file>");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	read_from_file(fd);
	fclose(fd);
	return (0);
}

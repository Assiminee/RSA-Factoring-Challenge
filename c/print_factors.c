#include "factors.h"

/**
 * print_factors - prints factors of a number
 * @number: number to factorize
 *
 * Return: void
 */
void print_factors(int number)
{
	int sqrt_num = (int)floor(sqrt(abs(number))), i;

	for (i = 2; i <= sqrt_num; i++)
	{
		if (i == sqrt_num && abs(number) % sqrt_num != 0)
		{
			printf("%d=%d*%d\n", number, number, 1);
			return;
		}
		if (abs(number) % i == 0)
		{
			printf("%d=%d*%d\n", number, number / i, i);
			return;
		}
	}
}

/**
 * read_from_file - reads from the file one line at a time
 * @fd: file descriptor
 *
 * Return: void
 */
void read_from_file(FILE *fd)
{
	char *line = malloc(1024);

	while (fgets(line, 1024, fd))
	{
		if (line[0] == '\n')
		{
			free(line);
			break;
		}
		printf("%lld\n", strtoll(line, NULL, 10));
		/* print_factors(atoi(line)); */
	}
}

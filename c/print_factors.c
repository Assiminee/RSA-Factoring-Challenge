#include "factors.h"

/**
 * print_factors - prints factors of a number
 * @number: number to factorize
 *
 * Return: void
 */
void print_factors(float number)
{
	float sqrt_num = floor(sqrtf(fabs(number))), i;

	for (i = 2.0; i <= sqrt_num; i += 1.0)
	{
		if (i == sqrt_num && fmod(fabs(number), sqrt_num))
		{
			printf("%.f=%.f*%d\n", number, number, 1);
			return;
		}
		if (!fmod(fabs(number), i))
		{
			printf("%.f=%.f*%.f\n", number, number / i, i);
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
	char *line = malloc(2048);

	while (fgets(line, 2048, fd))
	{
		if (line[0] == '\n')
		{
			free(line);
			break;
		}
		/* print_factors(atof(line)); */
		printf("%s\n%.f\n\n", line, strtod(line, NULL));
	}
}

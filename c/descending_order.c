/*

Your task is to make a function that can take any non-negative integer as an
argument and return it with its digits in descending order. Essentially, rearrange
the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421
Input: 145263 Output: 654321
Input: 123456789 Output: 987654321

*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int get_nb_length(uint64_t nb);
void sort_nb(char *str);

// 0 error handling
uint64_t descendingOrder(uint64_t nb)
{
	uint64_t nb_sort;
	char *itoa;
	int nb_length;

	if (nb < 12)
		return (nb);
	nb_length = get_nb_length(nb);
	itoa = calloc(nb_length + 1, sizeof(char));
	snprintf(itoa, nb_length + 1, "%lu", nb);
	itoa[nb_length] = '\0';
	sort_nb(itoa);
	nb_sort = strtoul(itoa, NULL, 10);
	free(itoa);
	return (nb_sort);
}

int get_nb_length(uint64_t nb)
{
	int length;

	length = 0;
	while (nb)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

void sort_nb(char *str)
{
	int i;
	int j;
	char temp;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] > str[i])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
}

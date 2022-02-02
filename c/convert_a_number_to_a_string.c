/*

We need a function that can transform a number into a string.

What ways of achieving this do you know?

In C, return a dynamically allocated string that will be freed by the test suite.

Examples:
123 --> "123"
999 --> "999"

*/

#include <stdlib.h>
int get_nb_length(int nb);

const char *number_to_string(int number)
{
	char *str;
	int is_negative;
	int nb_length;
	int i;

	is_negative = 0;
	if (!number)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	nb_length = get_nb_length(number);
	if (number < 0)
	{
		is_negative = 1;
		number *= -1;
		nb_length++;
	}
	str = malloc(sizeof(char) * (nb_length + 1));
	if (!str)
		return (NULL);
	if (is_negative)
		str[0] = '-';
	str[nb_length] = '\0';
	while (number)
	{
		str[nb_length - 1] = number % 10 + 48;
		number /= 10;
		nb_length--;
	}
	return (str);
}

int get_nb_length(int nb)
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

/*

Complete the square sum function so that it squares each number passed into it
and then sums the results together.

For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.

*/

#include <stddef.h>

int square_sum(const int *values, size_t count)
{
	int result;
	size_t i;

	result = 0;
	i = 0;
	while (i < count)
	{
		result += values[i] * values[i];
		i++;
	}
	return (result);
}

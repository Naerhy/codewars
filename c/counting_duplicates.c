/*

Write a function that will return the count of distinct case-insensitive
alphabetic characters and numeric digits that occur more than once in the input
string. The input string can be assumed to contain only alphabets (both
uppercase and lowercase) and numeric digits.

Example:
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice

*/

#include <stddef.h>

size_t already_exists(char *str, size_t index, int type);
size_t count_duplicates(char *str, char c, size_t start, int type);
int get_type(char c);

size_t duplicate_count(const char *str)
{
	size_t duplicates;
	size_t i;

	duplicates = 0;
	i = 0;
	while (str[i])
	{
		if (!already_exists(str, i, get_type(str[i]))
				&& count_duplicates(str, str[i], i + 1, get_type(str[i])))
			duplicates++;
		i++;
	}
	return (duplicates);
}

size_t already_exists(char *str, size_t index, int type)
{
	size_t i;

	i = 0;
	while (i < index)
	{
		if (str[i] == str[index] || (type == 1 && str[i] == str[index] - 32)
				|| (type == 2 && str[i] == str[index] + 32))
			return (1);
		i++;
	}
	return (0);
}

size_t count_duplicates(char *str, char c, size_t start, int type)
{
	size_t count;
	
	count = 0;
	while (str[start])
	{
		if (str[start] == c
				|| (type == 1 && str[start] == c - 32)
				|| (type == 2 && str[start] == c + 32))
			count++;
		start++;
	}
	return (count);
}

int get_type(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (-1);
}

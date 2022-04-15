/*

An isogram is a word that has no repeating letters, consecutive or
non-consecutive. Implement a function that determines whether a string that
contains only letters is an isogram. Assume the empty string is an isogram.
Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true
"aba" --> false
"moOse" --> false (ignore letter case)

*/

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool IsIsogram(const char *string)
{
	int length = strlen(string);
	if (!length)
		return true;

	for (int i = 0; i + 1 < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (islower(string[i]) &&
					(string[i] == string[j] || string[i] - 32 == string[j]))
				return false;
			if (isupper(string[i]) &&
					(string[i] == string[j] || string[i] + 32 == string[j]))
				return false;
		}
	}
	return true;
}

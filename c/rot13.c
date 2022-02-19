/*

ROT13 is a simple letter substitution cipher that replaces a letter with the
letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13.
If there are numbers or special characters included in the string, they should
be returned as they are. Only letters from the latin/english alphabet should be
shifted, like in the original Rot13 "implementation".

*/

#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

char *rot13(const char *src)
{
	char *rot;
	int i;

	rot = calloc(strlen(src) + 1, sizeof(char));
	if (!rot)
		return (NULL);
	i = 0;
	while (src[i])
	{
		if (isupper(src[i]))
		{
			if (src[i] + 13 <= 'Z')
				rot[i] = src[i] + 13;
			else
				rot[i] = src[i] - 13;
		}
		else if (islower(src[i]))
		{
			if (src[i] + 13 <= 'z')
				rot[i] = src[i] + 13;
			else
				rot[i] = src[i] - 13;
		}
		else
			rot[i] = src[i];
		i++;
	}
	return (rot);
}

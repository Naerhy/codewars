/*

Complete the solution so that it reverses the string passed into it.

'world'  =>  'dlrow'
'word'   =>  'drow'

*/

#include <string.h>

char *strrev(char *str)
{
	char *temp;
	size_t length;
	size_t i;

	length = strlen(str);
	temp = calloc(length + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < length)
	{
		temp[i] = str[length - i - 1];
		i++;
	}
	temp[i] = '\0';
	str = strcpy(str, temp);
	free(temp);
	return (str);
}

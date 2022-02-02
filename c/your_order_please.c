/*

Your task is to sort a given string. Each word in the string will contain a
single number. This number is the position the word should have in the result.

Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

If the input string is empty, return an empty string. The words in the input
String will only contain valid consecutive numbers.

Examples:
"is2 Thi1s T4est 3a"  -->  "Thi1s is2 3a T4est"
"4of Fo1r pe6ople g3ood th5e the2"  -->  "Fo1r the2 g3ood 4of th5e pe6ople"
""  -->  ""

*/

char *reset_str(char *str);
int check_number(const char *str, int nb);
void place_word(char *ordered, char *words, int nb);
void ny_strcat(char *dest, char *src);
int ny_strlen(const char *str);

// ordered is pre-allocated
// and has enough room for a trailing space character ' '
char *order_words(char *ordered, const char *words)
{
	int i;

	ordered = reset_str(ordered); // in case they don't clear previous str
	i = 1;
	while (check_number(words, i + 48))
	{
		place_word(ordered, (char *)words, i + 48);
		i++;
	}
	ordered[ny_strlen(ordered) - 1] = '\0';
	return (ordered);
}

char *reset_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

int check_number(const char *str, int nb)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

void place_word(char *ordered, char *words, int nb)
{
	char *begin;
	int i;

	begin = words;
	i = 0;
	while (words[i])
	{
		if (words[i] == ' ')
			begin = &words[i + 1];
		if (words[i] == nb)
			ny_strcat(ordered, begin);
		i++;
	}
}

void ny_strcat(char *dest, char *src)
{
	int dest_length;
	int i;

	dest_length = ny_strlen(dest);
	i = 0;
	while (src[i] && src[i] != ' ')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = ' ';
	dest[dest_length + i + 1] = '\0';
}

int ny_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

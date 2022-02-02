#include <stdlib.h>
#include <string.h>

const char *get_morse(const char *str, int n);

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
	"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
	".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----",
	".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
	"----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.",
	"-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-",
	"..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};

const char *ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",
	"I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",
	"T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",
	"3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",
	",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",
	":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",
	"@",      "SOS"};

char *decode_morse(const char *morse_code)
{
	char *decode;
	int start_index;
	int i;

	if (!morse_code)
		return (NULL);
	decode = calloc(strlen(morse_code), sizeof(char));
	if (!decode)
		return (NULL);
	i = 0;
	while (morse_code[i])
	{
		if (morse_code[i] && morse_code[i] != ' ')
		{
			start_index = i;
			while (morse_code[i] && morse_code[i] != ' ')
				i++;
			decode = strcat(decode, get_morse(&morse_code[start_index], i - start_index));
		}
		else if (i && morse_code[i -1] != ' ' && morse_code[i] == ' ' && morse_code[i + 1] == ' '
				&& morse_code[i + 2] == ' ' && (morse_code[i + 3] && morse_code[i + 3] != ' '))
		{
			decode = strcat(decode, " ");
			i += 3;
		}
		else
			i++;
	}
	return (decode);
}

const char *get_morse(const char *str, int n)
{
	int i;

	i = 0;
	while (i < 55)
	{
		if ((size_t)n == strlen(morse[i]) && !strncmp(str, morse[i], n))
			return (ascii[i]);
		i++;
	}
	return (NULL);
}

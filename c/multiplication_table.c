/*

Your task, is to create NxN multiplication table, of size provided in parameter.

for example, when given size is 3:
1 2 3
2 4 6
3 6 9
for given example, the return value should be: [[1,2,3],[2,4,6],[3,6,9]]

Note: in C, you must return an allocated table of allocated rows

*/

#include <stdlib.h>

int **multiplication_table(int n)
{
	int **table;

	table = calloc(n + 1, sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		table[i] = calloc(n + 1, sizeof(int));
		for (int j = 0; j < n; j++)
			table[i][j] = (i + 1) * (j + 1);
	}
	return (table);
}

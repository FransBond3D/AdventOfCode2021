#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_nr(char* &s)
{
	int nr = 0;
	while ('0' <= *s && *s <= '9')
		nr = 10 * nr + *s++ - '0';
	return nr;
}

int nrs[2000];

int main(int argc, char *argv[])
{
	char line[10000];
	fgets(line, 10000, stdin);
	int n = 0;
	printf("%s\n", line);

	for (char *s = line; '0' <= *s && *s <= '9';)
	{
		nrs[n++] = get_nr(s);
		if (*s == ',')
			s++;
	}
	for (int i = 0; i < n; i++)
		printf("%d,", nrs[i]);
	printf("\n");
	
	int min = -1;
	int min_v = -1;
	for (int v = 0; v < 2000; v++)
	{
		long dist = 0;
		for (int i = 0; i < n; i++)
			dist += abs(v - nrs[i]);
		//printf("%4d %5d\n", v, dist);
		
		if (min_v == -1 || dist < min)
		{
			min_v = v;
			min = dist;
		}
	}
	printf("\n\n%d %d\n", min_v, min);
}
/*
filename		:		Horspool.c
path			:		./
date			:		2015-11-19
author		 	:		bulldozer.ma
version			:		1.0
note			:		N/A
*/

#include <stdio.h>
#include <string.h>

/***************************************
*Function		:	Horspool
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *str, int *arr, int len
*Output			:	N/A
*Return			:	void
*Other			:	N/A
*Description	:	N/A
***************************************/
char *Horspool (char *str, int str_len, char *pattern, int len)
{	
	if (!str || !pattern || 0 >= str_len ||0 >= len)
	{
		return NULL;
	}

	int i, j = 0, k;
	char ch;

	while (j <= str_len - len)
	{
		for (i = len-1; i >= 0 && pattern[i] == str[i+j]; i--)
		{	
			if (0 == i)
			{
				return str + j;
			}
		}

		ch = str[i + j];
		k = i;
		while (0 < i && ch != pattern[--i])
		{
			if (0 == i)
			{
				j++;
			}
		}
		j += k-i;
	}
	return NULL;
}

int main(void)
{
	char str[] = "sfregfgghhhhf", pattern[] = "fggh";
	int i, len = strlen(pattern);
	char *p;

	p = Horspool(str, strlen(str), pattern, len);
	if (p)
	{
		for (i = 0; i < len; i++)
		{
			printf("%3c",*(p+i));
		}
	}
	else
	{
		printf("no found\r\n");
	}

	printf("\r\n");
	return 0;
}
/*
---------------------------------------------------------------------
yyyy-mm-dd			author			description
---------------------------------------------------------------------
2015-11-19			bulldozer.ma	practice
---------------------------------------------------------------------
*/


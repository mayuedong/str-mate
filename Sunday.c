/*
filename		:		Sunday.c
path			:		./
date			:		2015-11-19
author		 	:		bulldozer.ma
version			:		1.0
note			:		N/A
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***************************************
*Function		:	Sunday
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *str, int str_len,char *pattern, int len
*Output			:	N/A
*Return			:	void
*Other			:	N/A
*Description		:	N/A
***************************************/
char *Sunday (char *str, int str_len, char *pattern, int len)
{
	if (!str || !pattern || 0 >= str_len ||0 >= len)
	{
		return NULL;
	}
	int i, j, *arr;
	
	arr = (int *)malloc(sizeof(int)*256);
	if (!arr)
	{
		return NULL;
	}

	i = 256;
	while (i)
	{
		arr[--i] = -1;
	}
	for (i = 0; i < len; i++)
	{
		arr[pattern[i]] = i;
	}
	
	j = 0;
	while (j <= str_len - len)
	{
		for (i = len-1; i >= 0 && pattern[i] == str[i + j]; i--)
		{	
			if (0 == i)
			{
				free(arr);
				return str + j;
			}
		}
		j += len - arr[str[len + j]];
	}
	free(arr);
	return NULL;
}

int main(void)
{
	char str[] = "sfregfgghhhhf", pattern[] = "fggh";
	int i, len = strlen(pattern);
	char *p;

	p = Sunday(str, strlen(str), pattern, len);
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
2015-11-19			bulldozer.ma		practice
---------------------------------------------------------------------
*/

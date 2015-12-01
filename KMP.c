/*
filename		:		KMP.c
path			:		./
date			:		2015-11-19
author		 	:		bulldozer.ma
version			:		1.0
note			:		N/A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************
*Function		:	KMP
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *str, int *arr, int len
*Output			:	N/A
*Return			:	void
*Other			:	N/A
*Description		:	N/A
***************************************/
static void KMP(char *pattern, int len, int *arr)
{
	int i = 0, j = -1;

	arr[0] = -1;
	while (i < len-1)
	{
		if (-1 == j || pattern[i] == pattern[j])
		{
			i++;
			j++;
			if (pattern[i] != pattern[j])
			{
				arr[i] = j;
			}
			else
			{
				arr[i] = arr[j];
			}
		}
		else
		{
			j = arr[j];
		}
	}
}
/***************************************
*Function		:	mate
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *str, char *pattern, int str_len, int len
*Output			:	N/A
*Return			:	char *
*Other			:	N/A
*Description		:	N/A
***************************************/
char *mate(char *str, int str_len, char *pattern, int len)
{
	int i = 0, j = 0;

	int *arr = (int *)malloc(sizeof(int)*len);
	if (NULL == arr)
	{
		return NULL;
	}

	KMP(pattern, len, arr);
	while (i < str_len && j < len)
	{
		if (str[i] == pattern[j] || -1 == j)
		{
			i++;
			j++;
		}
		else
		{
			j = arr[j];
		}
	}
	if (j == len)
	{
		free(arr);
		arr = NULL;
		return str + i - j;
	}
	free(arr);
	arr = NULL;
	return NULL;
}

int main(void)
{
	char str[] = "sfregfgghhhhf",pattern[] = "fggh";
	int i, len = strlen(pattern);
	char*p;

	p = mate(str, strlen(str), pattern, len);
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

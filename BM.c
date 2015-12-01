/*
filename		:		BM.c
path			:		./
date			:		2015-11-19
author		 	:		bulldozer.ma
version			:		1.0
note			:		N/A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void applyArr(int **p, int len)
{
	*p = (int *)malloc(sizeof(int)*len);
	if (!*p)
	{
		return;
	}
}

static void freeArr(int **p)
{
	free(*p);
	*p = NULL;
}

/***************************************
*Function		:	badCharacter
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *pattern, int len
*Output			:	N/A
*Return			:	int *
*Other			:	N/A
*Description	:	N/A
***************************************/
int *badCharacter(char *pattern, int len)
{
	if (!pattern || 0 >= len)
	{
		return NULL;
	}
	
	int *arr;
	applyArr(&arr, 256);

	int i = 256;
	while (i)
	{
		arr[--i] = len;
	}
	
	while (len)
	{
		arr[*pattern++] = --len;
	}
	return arr;
}
/***************************************
*Function		:	upfrontGoodSuffix
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *pattern, int len
*Output			:	N/A
*Return			:	int *
*Other			:	N/A
*Description	:	N/A
***************************************/
int *upfrontGoodSuffix(char *pattern, int len)
{
	if (!pattern || 0 >= len)
	{
		return NULL;
	}
	
	int *arr;
	applyArr(&arr, len);
	
	int i, j;
	arr[len-1] = len;
	for (i = len - 2; i >= 0; i--)
	{	
		j = i;
		while (0 <= j && pattern[j] == pattern[len-1 - (i - j)])
		{
			j--;
		}
		arr[i] = i - j;
	}
	return arr;
}
/***************************************
*Function		:	goodSuffix
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *pattern, int len
*Output			:	N/A
*Return			:	int *
*Other			:	N/A
*Description	:	N/A
***************************************/
int *goodSuffix(char *pattern, int len)
{
	if (!pattern || 0 >= len)
	{
		return NULL;
	}
	
	int *arr, *suffixArr;
	
	applyArr(&arr, len);
	if (!arr)
	{
		return NULL;
	}

	suffixArr = upfrontGoodSuffix(pattern, len);
	if (!suffixArr)
	{
		freeArr(&arr);
		return NULL;
	}

	int i = 0;
	while (i < len)
	{
		arr[i++] = len;
	}
	
	int j = 0;
	for (i = len - 1; i >= 0; i--)
	{
		if (i + 1 == suffixArr[i])
		{
			while (j < len-1 - i)
			{
				if (len == arr[j])
				{
					arr[j] = len-1 - i;
				}
				j++;
			}
		}
	}

	for (i = 0; i < len - 1; i++)
	{
		arr[len-1 - suffixArr[i]] = len-1 - i;
	}
	freeArr(&suffixArr);
	return arr;
}
/***************************************
*Function		:	mate
*author			:	bulldozer.ma
*date			:	2015-11-19
*Intput			:	char *str, int str_len,char *pattern, int len
*Output			:	N/A
*Return			:	char *
*Other			:	N/A
*Description	:	N/A
***************************************/
char *mate(char *str, int str_len,char *pattern, int len)
{
	if (!str || !pattern || 0>=str_len ||0 >= len)
	{
		return NULL;
	}
	int *pBadArr, *pGoodArr;
	
	pBadArr = badCharacter(pattern, len);
	if (!pBadArr)
	{
		return NULL;
	}
	
	pGoodArr = goodSuffix(pattern, len);
	if (NULL == pGoodArr)
	{
		freeArr(&pBadArr);
		return NULL;
	}
	
	int i , j = 0;
	while (j <= strlen(str) - strlen(pattern))
	{
		for (i = len-1; i >= 0 && str[i+j] == pattern[i];i--)
		{
			if (0 == i)
			{
				freeArr(&pBadArr);
				freeArr(&pGoodArr);
				return str + j;
			}
		}
		j += pGoodArr[i] > (pBadArr[str[i+j]]-(len-1-i)) ? pGoodArr[i] : (pBadArr[str[i+j]] - (len-1-i));
	}
	freeArr(&pBadArr);
	freeArr(&pGoodArr);
	printf("myd\r\n");
	return NULL;
}

int main(void)
{
	char str[] = "sfggregfgghhhhf", pattern[] = "fggh";
	int i, len = strlen(pattern);
	char *p;

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
2015-11-19			bulldozer.ma	practice
---------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int n = 8;

int ft_strlen(char *a)
{
	int i;

	i = 0;
	while(a[i])
		i++;
	return(i);
}

int if_safe(int tab[n], int row, int col)
{
	int i = 0;

	while(i < n)
	{
		if(tab[i] == col)
			return(-1);
		i++;
	}

	i = 0;
	while(i < row && i < col)
	{
		if(tab[i] - i == col - row)
			return(-1);
		i++;
	}

	i = 0;
	while(i < row && i < col)
	{
		if(tab[i] + i == col + row)
			return(-1);
		i++;
	}

	return(1);
}

int print_tab(int tab[n])
{
	int i;
	int j;

	j = 0;
	while(j < n)
	{
		i = 0;
		while(i < n)
		{
			if(i == tab[j])
				printf("D");
			else
				printf("-");
			i++;
		}
		printf("\n");
	j++;
	}
	printf("\n");

	return(0);
}

int nq(int tab[n], int row)
{
	int i = 0;

	if(row == n)
	{
		printf("trouve!\n");
		print_tab(tab);
		return(1);
	}

	while(i < n)
	{
		if(if_safe(tab, row, i))
		{
			tab[row] = i;
			nq(tab, row +1);
		}

		i++;
	}

	return(0);
}

int main ()
{
	
	int tab[n];

	int i = 0;
	while(i < n)
	{
		tab[i] = 9;
		i++;
	}
//	tab[1] = 2;




	nq(tab, 0);
	print_tab(tab);

	return(0);
}
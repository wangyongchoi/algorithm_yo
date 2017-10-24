#include <stdio.h>
char arr[11][11];
int main()
{
	for(int i = 1 ; i <= 10; ++i)
	{
		for(int j = 1 ; j <= 10; ++j)
		{
			if((i+j)%2 == 0)
				arr[i][j] = '*';
			else
				arr[i][j] = '.';
		}
	}
	int a,b;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= a; ++i)
	{
		for(int j = 1; j <= b; ++j)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}

#include <stdio.h>
int p[6] = {500, 100, 50, 10, 5, 1};
int d[1001];
int main()
{
	int n;
	scanf("%d", &n);
	n = 1000 - n;
	for(int i = 0; i <= n; ++i)
	{
		d[i] = -1;
	}
	d[0] = 0;
	for(int i = 0; i < 6; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			if(j-p[i] >= 0 && d[j-p[i]] != -1)
			{
				if(d[j] == -1 || d[j] > d[j-p[i]] + 1)
				{
					d[j] = d[j-p[i]] + 1;
				}
			}
		}
	}
	printf("%d\n", d[n]);
	return 0;
}

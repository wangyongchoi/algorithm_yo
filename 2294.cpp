#include <stdio.h>
int d[10001];
int p[101];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &p[i]);
	}
	for(int i = 1; i <= k; ++i)
	{
		d[i] = -1;
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= k; ++j)
		{
			if(j - p[i] >= 0 && d[j-p[i]] != -1)
			{
				if(d[j] == -1 || d[j] > d[j-p[i]] + 1)
				{
					d[j] = d[j-p[i]] + 1;
				}
			}
		}
	}
	printf("%d\n", d[k]);
	return 0;
}

#include <stdio.h>
long long d[101][10];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 9; ++i)
		d[1][i] = 1;
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 0; j <= 9; ++j)
		{
			d[i][j] = 0;
			if(j-1 >= 0)
				d[i][j] += d[i-1][j-1];
			if(j+1 <= 9)
				d[i][j] += d[i-1][j+1];
			d[i][j] %= 1000000000;
		}
	}
	long long ans = 0;
	for(int i = 0; i <= 9; ++i)
		ans += d[n][i];
	printf("%lld\n", ans%1000000000);
	return 0;
}

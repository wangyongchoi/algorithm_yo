#include <stdio.h>
long long d[1001][10];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 10; ++i)
		d[1][i] = 1;
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			for(int k = 0; k <= j; ++k)
			{
				d[i][j] += d[i-1][k];
				d[i][j] %= 10007;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < 10; ++i)
		ans += d[n][i];
	printf("%lld\n", ans%10007);
	return 0;
}

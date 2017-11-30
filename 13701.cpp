#include <stdio.h>
int bits[(1<<20) + 1];
int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		int x = n / 32;
		int y = n % 32;
		if(bits[x] & (1 << y))
			continue;
		printf("%d ", n);
		bits[x] += (1 << y);
	}
	printf("\n");
	return 0;
}

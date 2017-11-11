#include <stdio.h>
int d[11] = {0, };
int main()
{
	d[0] = 1;
	for(int i = 0 ; i < 11; ++i)
	{
		if(i-1 >= 0)
			d[i] += d[i-1];
		if(i-2 >= 0)
			d[i] += d[i-2];
		if(i-3 >= 0)
			d[i] += d[i-3];
	}

	int n;
	scanf("%d", &n);
	while(n--)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d\n", d[temp]);
	}
	return 0;
}

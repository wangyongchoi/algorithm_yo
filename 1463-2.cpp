#include <stdio.h>
#define MAX 3000000
int d[MAX] = {0, };
int main()
{
	int n;
	scanf("%d",&n);
	d[0] = 0;
	d[1] = 0;
	for(int i = 2; i <= n; ++i)
	{
		//d[n] = d[n-1] + 1
		d[i] = d[i-1] + 1;
	
		//d[n] = d[n/2] + 1
		if(i % 2 == 0 && d[i] > d[i/2] + 1)
		{
			d[i] = d[i/2] + 1;
		}
		
		//d[n] = d[n/3] + 1
		if(i % 3 == 0 && d[i] > d[i/3] + 1)
		{
			d[i] = d[i/3] + 1;
		}
	}
	printf("%d\n", d[n]);
	return 0;
}

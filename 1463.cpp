//D[n] -> N을 1로 만다는데 필요한 연산의 최소값.
//D[n] = D[n/3] + 1
//D[n] = D[n/2] + 1
//D[n] = D[n-1] + 1
//따라서 D[n] = min(d[n/3]+1, d[n/2]+1, d[n-1]+1)
#include <stdio.h>
#define MAX 3000000
int d[MAX] = {0, };
int go(int n)
{
	if(n == 1)
		return 0;
	if(d[n] > 0)
		return d[n];
	//n -> n-1
	d[n] = go(n-1) + 1;

	//n -> n/2
	if(n%2 == 0)
	{
		int temp = go(n/2) + 1;
		if(d[n] > temp)
			d[n] = temp;
	}

	//n -> n/3
	if(n%3 == 0)
	{
		int temp = go(n/3) + 1;
		if(d[n] > temp)
			d[n] = temp;
	}
	return d[n];
}
int main()
{
	int	n;
	scanf("%d", &n);
	printf("%d\n", go(n));
	return 0;
}

#include <stdio.h>
long long arr[10] = {0,};
void calc(long long n, long long ten)
{
	while(n > 0)
	{
		arr[n%10] += ten;
		n = n/10;
	}
}

void go(long long start, long long end, long long ten)
{
	while(start%10 != 0 && start <= end)
	{
		calc(start, ten);
		start++;
	}

	if(start > end) return;
	while(end % 10 != 9 && start <= end)
	{
		calc(end, ten);
		end--;
	}
	long long cnt = (end/10 - start/10 + 1);
	for(int i = 0 ; i < 10; ++i)
	{
		arr[i] += cnt * ten;
	}

	go(start/10, end/10, ten*10LL);
}

int main()
{
	long long n;
	scanf("%lld", &n);
	go(1, n, 1);
	for(int i = 0; i < 10; ++i)
	{
		printf("%lld ", arr[i]);
	}
	printf("\n");
	return 0;
}

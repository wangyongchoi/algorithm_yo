#include <stdio.h>
int b[(1<<20) + 1];
int n;
int index, offset;
int main()
{
	while(scanf("%d", &n) == 1)
	{
		index = n/32;
		offset = n%32;
		if(b[index] & (1 << offset))
			continue;
		printf("%d ", n);
		b[index] += (1 << offset);
	}
}

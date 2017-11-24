#include <stdio.h>
int cnt = 1;
void go(int n)
{
	if(n == 1)
		return;
	if(n%2 == 0)
		go(n/2);
	else
		go(3*n + 1);
	cnt++;
}
int main()
{
	int n;
	scanf("%d", &n);
	go(n);
	printf("%d\n", cnt);
}


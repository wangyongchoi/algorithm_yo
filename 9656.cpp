/*
그냥..
*/
#include <stdio.h>
int main()
{
	int n, turn = 1;
	scanf("%d",&n);
	while(n)
	{
		if(n-3>=0)
			n-=3;
		else if(n-1>=0)
			n-=1;
		turn++;
	}
	if(turn%2==1)
		printf("SK\n");
	else
		printf("CY\n");
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	int n, s=0;
	char com[10];
	scanf("%d", &n);
	while(n--)
	{
		int e;
		scanf("%s %d", com ,&e);
		if(!strcmp(com, "add"))
		{
            s|=(1<<e);

		}else if(!strcmp(com, "remove"))
        {
            s&=(~(1<<e));
               
        }else if(!strcmp(com, "check"))
        {
            if(s&(1<<e))
                printf("1\n");
            else
                printf("0\n");
               
        }else if(!strcmp(com, "toggle"))
        {
            s^=(1<<e);
               
        }else if(!strcmp(com, "all"))
        {
            for(int i = 1; i <= 20; ++i)
            {
                s|=(1<<i);
            }
               
        }else if(!strcmp(com, "empty"))
        {
            s = 0;
        }
	}
}

#include <stdio.h>
#define MAX 13
#define INF 2147483600
int opp[4], arr[MAX], ret, n;
int max_num, min_num;
void dfs(int value, int count)
{
    if(count == n)
    {
        min_num = min_num > value ? value : min_num;
        max_num = max_num < value ? value : max_num;
        return;
    }
    if(opp[0])
    {
        --opp[0];
        dfs(value+arr[count], count+1);
        ++opp[0];
    }
    if(opp[1])
    {
        --opp[1];
        dfs(value-arr[count], count+1);
        ++opp[1];
    }
    if(opp[2])
    {
        --opp[2];
        dfs(value*arr[count], count+1);
        ++opp[2];
    }
    if(opp[3])
    {
        --opp[3];
        dfs(value/arr[count], count+1);
        ++opp[3];
    }
}

int main(void)
{
	int test_case;
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
        max_num = -INF;
        min_num = INF;
		scanf("%d", &n);
        for(int i = 0 ; i < 4; ++i)
        {
            scanf("%d", &opp[i]);
        }
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        dfs(arr[0], 1);
        printf("#%d %d\n",test_case, max_num-min_num);
	}
	return 0;
}
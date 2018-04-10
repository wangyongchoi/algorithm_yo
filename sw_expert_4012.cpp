#include <stdio.h>
#include <iostream>
#define MAX 20
#define INF 2147483647;
using namespace std;
int n, ans;
bool check[MAX];
int map[MAX][MAX];
void dfs(int cnt, int a_cnt)
{
    if(n == cnt)
    {
        int a, b;
        a = b = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(i == j)
                    continue;
                if(check[i] && check[j])
                    a += map[i][j];
                if(!check[i] && !check[j])
                    b += map[i][j];
            }
        }
        int ret = abs(a-b);
        ans = ans < ret ? ans : ret;
        return;
    }
    if(a_cnt > 0)
    {
        check[cnt] = true;
        dfs(cnt+1, a_cnt-1);
        check[cnt] = false;
    }
    dfs(cnt+1, a_cnt);
}
int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                int synergy;
                scanf("%d", &synergy);
                map[i][j] = synergy;
            }
        }
        ans = INF;
        dfs(0, n/2);
        printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
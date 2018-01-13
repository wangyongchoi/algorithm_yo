#include <cstdio>
#define MAX 20
int n;
int power[MAX][MAX];
int min = 2147483647;
void power()
void dfs(int index, int team1, int team2)
{
    if(index >= n)
    {
        int power1 = 0, power2 = 0;

        for(int i = team1.)
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &power[i][j]);
        }
    }
    dfs(0, n/2, n/2);
    printf("%d\n", min);
    return 0;
}
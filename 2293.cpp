#include <cstdio>
#define MAX 10000
int n,k;
int v[MAX];
int dp[MAX];
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &v[i]);
    }
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = v[i]; j <= k; ++j)
        {
            dp[j] += dp[j-v[i]];
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}

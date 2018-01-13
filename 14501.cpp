#include <cstdio>
#define MAX 30
int n;
int dp[MAX];
int main()
{
    scanf("%d", &n);
    for(int i = 0 ; i < n; ++i)
    {
        int t,p;
        scanf("%d %d", &t, &p);
        if(dp[i] > dp[i+1])
            dp[i+1] = dp[i];
        if(dp[i+t] < dp[i] + p)
            dp[i+t] = dp[i] + p;
    }
    printf("%d\n", dp[n]);
    return 0;
}

#include <cstdio>
#define MAX 21
int n, s;
int cnt = 0;
int arr[MAX];
void dfs(int pos, int ret)
{
    if(pos >= n)
        return;
    if(ret + arr[pos] == s)
        cnt++;
    dfs(pos+1, ret+arr[pos]);
    dfs(pos+1, ret);
}
int main()
{
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    dfs(0, 0);
    printf("%d\n", cnt);
    return 0;
}

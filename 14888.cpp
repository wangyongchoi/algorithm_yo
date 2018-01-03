#include <cstdio>
int n;
int arr[11];
int opp[4];
int max = -2147483621;
int min = 2147284642;
void dfs(int count, int value)
{
    if(count == n)
    {
        min = min > value ? value : min;
        max = max < value ? value : max;
        return;
    }
    if(opp[0])
    {
        --opp[0];
        dfs(count+1, value+arr[count]);
        ++opp[0];
    }
    if(opp[1])
    {
        --opp[1];
        dfs(count+1, value-arr[count]);
        ++opp[1];
    }
    if(opp[2])
    {
        --opp[2];
        dfs(count+1, value*arr[count]);
        ++opp[2];
    }
    if(opp[3])
    {
        --opp[3];
        dfs(count+1, value/arr[count]);
        ++opp[3];
    }
    
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    for(int i = 0; i < 4; ++i)
        scanf("%d", &opp[i]);
    
    dfs(1, arr[0]);
    
    printf("%d\n%d\n", max, min);
}

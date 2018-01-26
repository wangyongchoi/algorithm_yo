#include <cstdio>
#include <string.h>
#include <algorithm>
#define MAX 105
using namespace std;
int n;
int cnt = 0 , res = 0;
int map[MAX][MAX];
int copy_map[MAX][MAX];
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};
void dfs(int row, int col, int h)
{
    copy_map[row][col] = 0;
    for(int i = 0; i < 4; ++i)
    {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];
        if(copy_map[next_row][next_col] > h)
        {
            dfs(next_row, next_col, h);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for(int i = 0; i <= 100; ++i)
    {
        memcpy(copy_map, map, sizeof(map));

        for(int j = 1; j <= n; ++j)
        {
            for(int k = 1; k <= n; ++k)
            {
                if(copy_map[j][k] > i)
                {
                    cnt++;
                    dfs(j,k,i);
                }
            }
        }
        res = max(cnt, res);
        cnt = 0;
    }
    printf("%d\n", res);
    return 0;
}
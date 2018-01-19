#include <cstdio>
#include <algorithm>
#define MAX 501
using namespace std;
int n,m;
int map[MAX][MAX];
int check[MAX][MAX];
int check2[MAX][MAX];
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};
int ret = 0;
int dfs(int row, int col, int count)
{
    if(count == 4)
    {
        return map[row][col];
    }
    check[row][col] = true;
    int res = map[row][col];
    for(int i = 0 ; i < 4; ++i)
    {
        int curr_row = row + d_row[i];
        int curr_col = col + d_col[i];
        if(curr_row < 0 || curr_col < 0 || curr_row >= n || curr_col >= m || check[curr_row][curr_col])
            continue;
        res = max(res, map[row][col] + dfs(curr_row, curr_col, count+1));
    }
    check[row][col] = false;
    return res;
}
int go(int row, int col)
{
    int max_value = 0;
    int arr[4] = {0, 0, 0, 0};
    bool arr_check[4];
    int res = map[row][col];
    for(int i = 0 ; i < 4; ++i)
    {
        int curr_row = row + d_row[i];
        int curr_col = col + d_col[i];
        if(curr_row < 0 || curr_col < 0 || curr_row >= n || curr_col >= m)
            arr[i] = 0;
        else
            arr[i] = map[curr_row][curr_col];
    }
    for(int i = 0; i < 4; ++i)
    {
        arr_check[i] = true;
        int temp_max = 0;
        for(int j = 0; j < 4; ++j)
        {
            if(arr_check[j] == true)
                continue;
            temp_max+=arr[j];
        }
        max_value = max(max_value, temp_max);
        arr_check[i] = false;
    }
    return max_value + res;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            ret = max(ret, dfs(i, j, 1));
            ret = max(ret, go(i, j));
        }
    }
    printf("%d\n", ret);
    return 0;
}
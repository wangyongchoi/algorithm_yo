#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 105
using namespace std;
int n,m,k;
int cnt = 0;
bool map[MAX][MAX];
bool check[MAX][MAX];
int d_row[4] = {0,0,1,-1};
int d_col[4] = {1,-1,0,0};
vector<int> v;
void dfs(int row, int col)
{
    for(int i = 0 ; i < 4; ++i)
    {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];
        if(next_row < 0 || next_col < 0 || next_row >= n || next_col >= m || check[next_row][next_col])
            continue;
        if(!map[next_row][next_col])
        {
            cnt++;
            check[next_row][next_col] = true;
            dfs(next_row, next_col);
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; ++i)
    {
        int lx,ly,rx,ry;
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
        for(int j = ly; j < ry; ++j)
        {
            for(int k = lx; k < rx; ++k)
            {
                map[j][k] = true;
            }
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(!map[i][j] && !check[i][j])
            {
                check[i][j] = true;
                cnt = 1;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(int i = 0 ; i < v.size(); ++i)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}
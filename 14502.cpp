#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#define MAX 9
#define BLANK 0
#define WALL 1
#define VIRUS 2
using namespace std;

int n, m;
int map[MAX][MAX];
bool check[MAX][MAX];
vector<pair<int, int> > v;
int d_row[4] = {1, 0, 0, -1};
int d_col[4] = {0, 1, -1, 0};
int max_res = 0;

void bfs()
{
    queue<pair<int, int> > q;
    for(int i = 0 ; i < v.size(); ++i)
    {
        q.push(v[i]);
    }

    while(!q.empty())
    {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int next_row = curr_row + d_row[i];
            int next_col = curr_col + d_col[i];
            if(next_row < 0 || next_col < 0 || next_row >= n || next_col >= m || map[next_row][next_col] != BLANK)
                continue;
            map[next_row][next_col] = VIRUS;
            q.push(make_pair(next_row, next_col));
        }
    }
}
int count_map(int (*a)[MAX], int (*b)[MAX])
{
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            if(a[i][j] == BLANK)
                res++;
            a[i][j] = b[i][j];
        }
    }
    return res;
}
void dfs(int row, int col, int wall)
{
    map[row][col] = WALL;
    check[row][col] = true;

    if(wall == 3)
    {
        int t_map[MAX][MAX];
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0 ; j < m; ++j)
            {
                t_map[i][j] = map[i][j];
            }
        }

        bfs();

        max_res = max(max_res, count_map(map, t_map));

        map[row][col] = BLANK;
        check[row][col] = false;
        return;
    }

    for(int i = row; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            if(check[i][j] || map[i][j] != BLANK)
                continue;
            dfs(i, j, wall+1);
        }
    }
    map[row][col] = BLANK;
    check[row][col] = false;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == VIRUS)
                v.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            if(map[i][j] != BLANK)
                continue;
            dfs(i, j, 1);
        }
    }
    printf("%d\n", max_res);
    return 0;
}
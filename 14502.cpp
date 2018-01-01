#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#define MAX 8
using namespace std;

int map[MAX][MAX];
bool check[MAX][MAX];
vector<pair<int, int> > virus;
int n, m;
int wall = 0;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int max_res = 0;

void copy_map(int (*a)[MAX], int (*b)[MAX])
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            a[i][j] = b[i][j];
        }
    }
}

int count_map(int (*a)[MAX], int (*b)[MAX])
{
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(a[i][j] == 0)
                res++;
            a[i][j] = b[i][j];
        }
    }
    return res;
}

void bfs()
{
    queue<pair<int, int> > q;
    for(int i = 0; i < virus.size(); ++i)
        q.push(virus[i]);
    
    while(!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];
            if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m || map[next_x][next_y] != 0)
                continue;
            map[next_x][next_y] = 2;
            q.push(make_pair(next_x, next_y));
        }
    }
}

void dfs(int x, int y, int wall)
{
    map[x][y] = 1;
    check[x][y] = true;
    if(wall == 3)
    {
        int t_map[MAX][MAX];
        copy_map(t_map, map);
        
        bfs();
        max_res = max(max_res, count_map(map, t_map));
        
        map[x][y] = 0;
        check[x][y] = false;
        return;
    }

    for(int i = x; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(check[i][j] || map[i][j] != 0)
                continue;
            dfs(i, j, wall+1);
        }
    }
    
    map[x][y] = 0;
    check[x][y] = false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(map[i][j] != 0)
                continue;
            dfs(i, j, 1);
        }
    }
    printf("%d\n", max_res);
    return 0;
}

#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
#define MAX 1001
using namespace std;
int n,m,res;
int hx,hy;
int ex,ey;
int map[MAX][MAX];
bool check[MAX][MAX][2];
int dist[MAX][MAX][2];
queue<pair<pair<int, int> , int> > q;
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};
void init()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            check[i][j][0] = false;
            check[i][j][1] = false;
            dist[i][j][0] = 0;
            dist[i][j][1] = 0;
        }
    }
}
void bfs()
{
    q.push(make_pair(make_pair(hx-1,hy-1),1));
    check[hx-1][hy-1][1] = true;
    dist[hx-1][hy-1][1] = 0;
    while(!q.empty())
    {
        int curr_row = q.front().first.first;
        int curr_col = q.front().first.second;
        int magic = q.front().second;
        q.pop();

        if(curr_row == ex-1 && curr_col == ey-1)
        {
            break;
        }
        for(int i = 0; i < 4; ++i)
        {
            int next_row = curr_row + d_row[i];
            int next_col = curr_col + d_col[i];
            if(next_col < 0 || next_row < 0 || next_row >= n || next_col >= m || check[next_row][next_col][magic])
                continue;
            check[next_row][next_col][magic] = true;
            if(map[next_row][next_col] == 0)
            {
                dist[next_row][next_col][magic] = dist[curr_row][curr_col][magic] + 1;
                q.push(make_pair(make_pair(next_row,next_col), magic));
            }else{//wall
                if(magic)
                {
                    dist[next_row][next_col][0] = dist[curr_row][curr_col][magic] + 1;
                    q.push(make_pair(make_pair(next_row,next_col), 0));
                }
            }
        }
    }

    if(dist[ex-1][ey-1][0] == 0 && dist[ex-1][ey-1][1] == 0)
        res = -1;
    else if(dist[ex-1][ey-1][0] == 0)
        res = dist[ex-1][ey-1][1];
    else if(dist[ex-1][ey-1][1] == 0)
        res = dist[ex-1][ey-1][0];
    else
        res = min(dist[ex-1][ey-1][0], dist[ex-1][ey-1][1]);
    return;
}
int main()
{
    init();
    scanf("%d %d %d %d %d %d", &n, &m, &hx, &hy, &ex, &ey);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &map[i][j]); 
        }
    }
    bfs();
    printf("%d\n",res);
    return 0;
}
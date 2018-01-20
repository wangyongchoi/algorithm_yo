#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#define MAX 51
using namespace std;
int t, res = 0;
int m,n,k;
int map[MAX][MAX];
bool check[MAX][MAX];
vector<pair<int, int> > v;
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};

void init()
{
    res = 0;
    v.clear();
    for(int i = 0 ; i < MAX; ++i)
    {
        for(int j = 0; j < MAX; ++j)
        {
            map[i][j] = 0;
            check[i][j] = false;
        }
    }
}
void bfs(int index)
{
    queue<pair<int, int> > q;
    q.push(v[index]);
    if(!check[v[index].first][v[index].second])
    {
        check[v[index].first][v[index].second] = true;
        res++;
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
            if(next_row < 0 || next_col < 0 || next_row >= n || next_col >= m || check[next_row][next_col] || map[next_row][next_col] != 1)
                continue;
            if(map[next_row][next_col] == 1)
                q.push(make_pair(next_row, next_col));
            check[next_row][next_col] = true;
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        scanf("%d %d %d", &m, &n, &k);
        for(int i = 0 ; i < k; ++i)
        {
            int col, row;
            scanf("%d %d", &col, &row);
            map[row][col] = 1;
            v.push_back(make_pair(row, col));
        }
        for(int i = 0 ; i < v.size(); ++i)
        {
            bfs(i);
        }
        printf("%d\n",res);
    }
}
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#define MAX 1001
using namespace std;
int n,m;
bool check[MAX][MAX][2];
int map[MAX][MAX];
int dist[MAX][MAX][2];
int res;
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};
void bfs()
{
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0,0), 1));
    check[0][0][1] = true;
    dist[0][0][1] = 1;
    while(!q.empty())
    {
        int curr_row = q.front().first.first;
        int curr_col = q.front().first.second;
        int key = q.front().second;
        q.pop();
        if(curr_row == n-1 && curr_col == m-1)
            break;
        for(int i = 0 ; i < 4; ++i)
        {
            int next_row = curr_row + d_row[i];
            int next_col = curr_col + d_col[i];
            if(next_row < 0 || next_col < 0 || next_row >= n || next_col >= m || check[next_row][next_col][key])
                continue;

            check[next_row][next_col][key] = true;
            if(map[next_row][next_col] == 0)
            {
                dist[next_row][next_col][key] = dist[curr_row][curr_col][key] + 1;
                q.push(make_pair(make_pair(next_row, next_col), key));
            }else{//wall
                if(key)
                {
                    dist[next_row][next_col][0] = dist[next_row][next_col][key] + 1;
                    q.push(make_pair(make_pair(next_row, next_col), 0));
                }
            }     
        }
    }
    if(dist[n-1][m-1][1] == 0 && dist[n-1][m-1][0] == 0)
        res = -1;
    else if(dist[n-1][m-1][0] == 0)
        res = dist[n-1][m-1][1];
    else if(dist[n-1][m-1][1] == 0)
        res = dist[n-1][m-1][0];
    else
        res = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    return;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; ++i)
    {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); ++j)
        {
            map[i][j] = str[j]-'0';
        }
    }
    bfs();
    printf("%d\n", res);
    return 0;
}
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define HEALTHY 0
#define UNHEALTHY 1
#define MAX 101
using namespace std;
int n;
char map[MAX][MAX];
bool check[2][MAX][MAX];
int cnt[2] = {0,0};
int d_row[4] = {1,0,0,-1};
int d_col[4] = {0,1,-1,0};
void bfs(int row, int col, int condition)
{
   if(check[condition][row][col])
       return;
   cnt[condition]++;
   queue<pair<int, int> > q;
   q.push(make_pair(row, col));
   while(!q.empty())
   {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        check[condition][curr_row][curr_col] = true;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int next_row = curr_row + d_row[i];
            int next_col = curr_col + d_col[i];
            if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || check[condition][next_row][next_col])
                continue;
            if(condition == HEALTHY)
            {
                if(map[curr_row][curr_col] != map[next_row][next_col])
                    continue;
            }else{
                if(map[curr_row][curr_col] == 'R' || map[curr_row][curr_col] == 'G')
                {
                    if(map[next_row][next_col] == 'B')
                        continue;
                }else{
                    if(map[next_row][next_col] == 'R' || map[next_row][next_col] == 'G')
                        continue;
                }
            }
            q.push(make_pair(next_row, next_col));
            check[condition][next_row][next_col] = true;
        }
   }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for(int j = 0 ; j < str.length(); ++j)
        {
            map[i][j] = str[j];
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            bfs(i,j,HEALTHY);
            bfs(i,j,UNHEALTHY);
        }
    }
    printf("%d %d\n", cnt[0], cnt[1]);
    return 0;
}
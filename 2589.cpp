#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#define MAX 51
using namespace std;
int n,m;
char map[MAX][MAX];
vector<pair<int, int> > v;
int res = 0;
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; ++i)
    {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); ++j)
        {
            map[i][j] = str[j];
            if(map[i][j] == 'L')
                v.push_back(make_pair(i,j));            
        }
    }

    for(int i = 0; i < v.size(); ++i)
    {
        bool check[MAX][MAX];
        for(int j = 0; j < MAX; ++j)
        {
            for(int k = 0; k < MAX; ++k)
            {
                check[j][k] = false;
            }
        }
        int dist[MAX][MAX] = {0};
        int max_dist = 0;
        queue<pair<int, int> > q;
        check[v[i].first][v[i].second] = true;
        q.push(v[i]);
        
        while(!q.empty())
        {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();

            for(int j = 0; j < 4; ++j)
            {
                int next_row = curr_row + d_row[j];
                int next_col = curr_col + d_col[j];
                if(next_row < 0 || next_col < 0 || next_row >= n || next_col >= m || check[next_row][next_col])
                    continue;
                if(map[next_row][next_col] == 'L')
                {
                    dist[next_row][next_col] = dist[curr_row][curr_col] + 1;
                    max_dist = max(dist[next_row][next_col] , max_dist);
                    check[next_row][next_col] = true;
                    q.push(make_pair(next_row, next_col));
                }
            }
        }
        res = max(res, max_dist);
    }

    printf("%d\n", res);
    return 0;
}
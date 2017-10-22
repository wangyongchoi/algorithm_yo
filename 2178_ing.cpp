#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
#define MAX 100
using namespace std;
int map[MAX][MAX];
bool check[MAX][MAX];
int dist[MAX][MAX];
queue<pair<int, int> > q;
int main()
{
	memset(map, 0, sizeof(map));
	memset(check, false, sizeof(check));
	memset(dist, 0, sizeof(dist));
	int n,m;
	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}

	q.push(make_pair(0,0));
	check[0][0] = true;
	dist[0][0] = 1;
	while(!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		
		//right
		int next_x = curr_x;
		int next_y = curr_y + 1;
		if(check[next_x][next_y] == false)
		{
            dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            check[next_x][next_y] = true;
            q.push(make_pair(next_x, next_y));
		}
        
        //left
        next_x = curr_x;
        next_y = curr_y - 1;
        if(check[next_x][next_y] == false)
        {
            dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            check[next_x][next_y] = true;
            q.push(make_pair(next_x, next_y));
        }
        
        //up
        next_x = curr_x - 1;
        next_y = curr_y;
        if(check[next_x][next_y] == false)
        {
            dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            check[next_x][next_y] = true;
            q.push(make_pair(next_x, next_y));
        }
        
        //down
        next_x = curr_x + 1;
        next_y = curr_y;
        if(check[next_x][next_y] == false)
        {
            dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
            check[next_x][next_y] = true;
            q.push(make_pair(next_x, next_y));
        }
	}
    
    printf("%d\n",dist[n][m]);
    return 0;
}

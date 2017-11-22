#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;
int map[1001][1001];
int check[1001][1001];
queue<pair<int,int> > q;
int main()
{
    memset(check, -1, sizeof(check));
	int n, m;
	pair<int,int> start;
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0 ; j < m; ++j)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2)
			{
				start.first = i;
				start.second = j;
			}else if(map[i][j] == 0)
            {
                check[i][j] = 0;
            }
		}
	}
	q.push(start);
    check[start.first][start.second] = 0;
	while(!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		//n
        int next_x = curr_x;
		int next_y = curr_y - 1;
		if(next_y >= 0 && map[next_x][next_y] && check[next_x][next_y] == -1)
		{
			check[next_x][next_y] = check[curr_x][curr_y]+1;
			q.push(make_pair(next_x,next_y));
		}
		
		//e
        next_x = curr_x + 1;
        next_y = curr_y;
        if(next_x < 1000 && map[next_x][next_y] && check[next_x][next_y] == -1)
        {
            check[next_x][next_y] = check[curr_x][curr_y]+1;
            q.push(make_pair(next_x,next_y));
        }
        
		//s
        next_x = curr_x;
        next_y = curr_y + 1;
        if(next_y < 1000 && map[next_x][next_y] && check[next_x][next_y] == -1)
        {
            check[next_x][next_y] = check[curr_x][curr_y]+1;
            q.push(make_pair(next_x,next_y));
        }

		//w
        next_x = curr_x - 1;
        next_y = curr_y;
        if(next_x >= 0 && map[next_x][next_y] && check[next_x][next_y] == -1)
        {
            check[next_x][next_y] = check[curr_x][curr_y]+1;
            q.push(make_pair(next_x,next_y));
        }
	}
    
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            printf("%d ", check[i][j]);
        }
        printf("\n");
    }
    return 0;
}


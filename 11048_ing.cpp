#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int check[1001][1001];
int map[1001][1001];
//int res = 0;
queue<pair<int, int> > q;
int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0 ; i < 1000; ++i)
	{
		for(int j = 0; j < 1000; ++j)
		{
			check[i][j] = 0;
			map[i][j] = 0;
		}
	}
	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

	q.push(make_pair(1,1));
	check[1][1] = 1;
	//res = map[1][1];

	while(!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		int next_x = curr_x+1;
		int next_y = curr_y;
		if(next_x <= m && !check[next_x][next_y])
		{
			q.push(make_pair(next_x,next_y));
			check[next_x][next_y] = 1;
			map[next_x][next_y] += map[curr_x][curr_y];
		}

        next_x = curr_x+1;
        next_y = curr_y+1;
        if(next_x <= n && next_y <= m && !check[next_x][next_y])
        {
            q.push(make_pair(next_x,next_y));
            check[next_x][next_y] = 1;
            map[next_x][next_y] += map[curr_x][curr_y];
        }
        
        next_x = curr_x;
        next_y = curr_y+1;
        if(next_y <= m && !check[next_x][next_y])
        {
            q.push(make_pair(next_x,next_y));
            check[next_x][next_y] = 1;
            map[next_x][next_y] += map[curr_x][curr_y];
        }
	}
    
    cout << endl;
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << map[n][m] << endl;
}


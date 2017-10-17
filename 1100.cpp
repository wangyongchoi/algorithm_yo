/*
배열의 크기가 작아 중첩 for문으로 처리가능해 보였지만
그냥 BFS를 연습하였다.
check 배열을 사용하였고, queue과 pair를 사용하여 좌표를 저장하였다.
0,0 인 출발점 좌표를 처리하기위해 삽입된 코드의 반복을 줄이려고 시도하다가 에러를 만들었다.
일반적인 BFS로 탐색이 가능하다.
*/

#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
#define MAX 8
using namespace std;

bool check[MAX][MAX];
char board[MAX][MAX];
queue<pair<int, int> > q;

int main()
{
    int count = 0;
    memset(check, false, sizeof(check));
    
	for(int i = 0; i < MAX; ++i)
	{
        scanf("%s",board[i]);
	}
	
	q.push(make_pair(0,0));
    
	while(!q.empty())
	{
		pair<int, int> curr_pair = q.front();
		int curr_x = curr_pair.first;
		int curr_y = curr_pair.second;
		q.pop();

		//west
		int next_x = curr_x - 1;
		int next_y = curr_y;
        if((next_x >= 0 && next_x < MAX) && (next_y >= 0 && next_y < MAX))
		{
			if(check[next_x][next_y] == false)
			{
                check[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
				if(((next_x + next_y == 0) || ((next_x + next_y)%2 == 0)) && (board[next_x][next_y] == 'F'))
				{
                    count++;
				}
			}
		}
		
		//east
        next_x = curr_x + 1;
        next_y = curr_y;
        if((next_x >= 0 && next_x < MAX) && (next_y >= 0 && next_y < MAX))
        {
            if(check[next_x][next_y] == false)
            {
                check[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
                if(((next_x + next_y == 0) || ((next_x + next_y)%2 == 0)) && (board[next_x][next_y] == 'F'))
                {
                    count++;
                }
            }
        }
        
		//north
        next_x = curr_x;
        next_y = curr_y - 1;
        if((next_x >= 0 && next_x < MAX) && (next_y >= 0 && next_y < MAX))
        {
            if(check[next_x][next_y] == false)
            {
                check[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
                if(((next_x + next_y == 0) || ((next_x + next_y)%2 == 0)) && (board[next_x][next_y] == 'F'))
                {
                    count++;
                }
            }
        }

		//south
        next_x = curr_x;
        next_y = curr_y + 1;
        if((next_x >= 0 && next_x < MAX) && (next_y >= 0 && next_y < MAX))
        {
            if(check[next_x][next_y] == false)
            {
                check[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
                if(((next_x + next_y == 0) || ((next_x + next_y)%2 == 0)) && (board[next_x][next_y] == 'F'))
                {
                    count++;
                }
            }
        }
	}
    
    printf("%d\n", count);
    return 0;
}

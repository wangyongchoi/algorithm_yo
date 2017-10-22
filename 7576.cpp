/*
BFS 문제로, 간단한데...
m n으로 입력이 들어와서
loop 주의하면 어렵지 않은 문제인듯
코드 정리할 필요성 있음
다시 풀것!!
*/
#include <stdio.h>
#include <queue>
#include <string.h>
#include <utility>
#define MAX 2000
using namespace std;
queue<pair<int,int> > q;
int box[MAX][MAX];
int time_box[MAX][MAX];

int main()
{
    memset(time_box, -1, sizeof(time_box));
    memset(box, -1, sizeof(box));
    int m,n;
    scanf("%d %d", &m, &n);
    for(int i = 1 ; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            scanf("%d",&box[i][j]);
            if(box[i][j] == 1)
            {
                time_box[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    
    int count = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        //west
        if(y-1 > 0 && box[x][y-1] == 0)
        {
            box[x][y-1] = 1;
            time_box[x][y-1] = time_box[x][y] + 1;
            if(count < time_box[x][y-1])
                count = time_box[x][y-1];
            q.push(make_pair(x,y-1));
        }
        //south
        if(x+1 <= n && box[x+1][y] == 0)
        {
            box[x+1][y] = 1;
            time_box[x+1][y] = time_box[x][y] + 1;
            if(count < time_box[x+1][y])
                count = time_box[x+1][y];
            q.push(make_pair(x+1, y));
        }
        //east
        if(y+1 <= m && box[x][y+1] == 0)
        {
            box[x][y+1] = 1;
            time_box[x][y+1] = time_box[x][y] + 1;
            if(count < time_box[x][y+1])
                count = time_box[x][y+1];
            q.push(make_pair(x, y+1));
        }
        //north
        if(x-1 > 0 && box[x-1][y] == 0)
        {
            box[x-1][y] = 1;
            time_box[x-1][y] = time_box[x][y] + 1;
            if(count < time_box[x-1][y])
                count = time_box[x-1][y];
            q.push(make_pair(x-1, y));
        }
        
    }
    
    //impossible check
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(box[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    
    printf("%d\n", count);
    return 0;
}

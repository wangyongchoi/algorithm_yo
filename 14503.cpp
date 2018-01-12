#include <cstdio>
#define MAX 51
#define BLANK 0
#define WALL 1
#define CLEAR 2
using namespace std;
int n,m,r,c,d;
//n e s w
int d_row[4] = { -1, 0, 1,  0};
int d_col[4] = {  0, 1, 0, -1};
int map[MAX][MAX];
int res = 0;
int next_d = 0;
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0 ; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }

    while(1)
    {
        //1
        if(map[r][c] == BLANK)
        {
            map[r][c] = CLEAR;
            res++;
        }

        bool all_clear = false;
        //2
        for(int i = 0; i < 4; ++i)
        {
            next_d = (d+4-1)%4;
            int next_r = r + d_row[next_d];
            int next_c = c + d_col[next_d];
            //2-1
            if(map[next_r][next_c] == BLANK)
            {
                d = next_d;
                r = next_r;
                c = next_c;
                all_clear = true;
                break;
            }//2-2
            else
            {
                d = next_d;
            }
        }
        if(!all_clear)
        {
            //2-3
            if(map[r - d_row[d]][c - d_col[d]] == WALL)
            {
                printf("%d\n", res);
                return 0;
            }//2-4
            else
            {
                r -= d_row[d];
                c -= d_col[d];
            }
        }
    }
}
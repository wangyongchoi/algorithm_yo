#include <cstdio>
#define MAX 51
using namespace std;

int n, m;
int r, c, d;
int map[MAX][MAX];
int dr[4] = {-1, 0, 1,  0}; // n e s w
int dc[4] = { 0, 1, 0, -1};
int res = 0;

void go()
{
    while(1)
    {
        //1
        if(map[r][c] == 0)
        {
            res++;
            map[r][c] = 2;
        }

        bool unclear = false;
        //2
        for(int i = 0; i < 4; ++i)
        {
            int next_d = (d+4 - 1) % 4;
            int next_r = r + dr[next_d];
            int next_c = c + dc[next_d];

            //2-1
            if(map[next_r][next_c] == 0)
            {
                d = next_d;
                r = next_r;
                c = next_c;
                unclear = true;
                break;
            }//2-2
            else{
                d = next_d;
            }
        }

        if(!unclear)
        {
            //2-4
            if(map[r-dr[d]][c-dc[d]] == 1)
            {
                printf("%d\n", res);
                break;
            }//2-3
            else{
                r-=dr[d];
                c-=dc[d];
            }
        }

    }
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
    go();
    return 0;
}

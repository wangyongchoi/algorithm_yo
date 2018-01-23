#include <cstdio>
#include <functional>
#include <vector>
#define MAX 101
using namespace std;
int n,k,l;
int map[MAX][MAX];
int res = 0;
char directions[MAX];
int d_row[4] = {0,1,0,-1};
int d_col[4] = {1,0,-1,0};
vector<pair<int, int> > body;
void init()
{
    for(int i = 0; i < MAX; ++i)
    {
        directions[i] = '0';
        for(int j = 0; j < MAX; ++j)
        {
            map[i][j] = 0;
        }
    }
}
void go()
{
    body.push_back(make_pair(0,0));
    int curr_d_row = 0;
    int curr_d_col = 0;
    int curr_row = 0;
    int curr_col = 0;
    while(1)
    {
        res++;
        curr_row += d_row[curr_d_row];
        curr_col += d_col[curr_d_col];
        printf("@ %ds : %d, %d\n", res, curr_row, curr_col);
        if(curr_row < 0 || curr_col < 0 || curr_row >= n || curr_col >= n)
            return;
        for(int i = 0 ; i < body.size(); ++i)
        {
            if(body[i].first == curr_row && body[i].second == curr_col)
                return;
        }
        body.push_back(make_pair(curr_row, curr_col));
        if(map[curr_row][curr_col] == 1)
        {  
            map[curr_row][curr_col] = 0;
        }
        else if(map[curr_row][curr_col] != 1)
        {
            body.erase(body.begin());
        }
        if(directions[res] == 'L' || directions[res] == 'D')
        {
            if(directions[res] == 'D')
            {
                curr_d_row = (curr_d_row+1)%4;
                curr_d_col = (curr_d_col+1)%4;
            }else{
                curr_d_row = (curr_d_row+4-1)%4;
                curr_d_col = (curr_d_col+4-1)%4;
            }
        }
    }
}
int main()
{
    init();
    scanf("%d %d", &n, &k);
    for(int i = 0 ; i < k; ++i)
    {
        int row, col;
        scanf("%d %d", &row, &col);
        map[row][col] = 1;
    }
    scanf("%d", &l);
    for(int i = 0 ; i < l; ++i)
    {
        int index;
        scanf("%d %c", &index, &directions[index]);
    }
    go();
    printf("%d\n", res);
    return 0;
}
#include <cstdio>
#include <vector>
#define MAX 20
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4
using namespace std;
int n;
int map[MAX][MAX];


void copy_map(int (*from)[MAX], int (*to)[MAX])
{
    for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                to[i][j] = from[i][j];
            }
        }
}

void move_map(int direction)
{
    if(direction == EAST)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = n-1; j >= 0; --j)
            {
                if(map[i][j] == 0 && j != 0)
                {
                    for(int k = j-1; k >= 0; --k)
                    {
                        if(map[i][k] != 0)
                        {
                            map[i][j] = map[i][k];
                        }else if(map[i][k] == map[i][j])
                        {
                            map[i][j] *= 2;
                        }
                        map[i][k] = 0;
                    }
                }
            }
        }

    }else if(direction == WEST)
    {

    }else if(direction == SOUTH)
    {

    }else if(direction == NORTH)
    {

    }
}
void go(int count)
{
    //max count
    if(count == 5)
    {
        int res = 0;
        for(int i = 0 ; i < n; ++i)
        {
            for(int j = 0 ; j < n; ++j)
            {
                res = res > map[i][j] ? res : map[i][j];
            }
        }
        return res;
    }

    int res = 0;
    //n s w e
    for(int i = 0 ; i < 4; ++i)
    {
        


        for(int j = 0; j < n; ++j)
        {
            vector<int> v;
            for(int k = 0; k < n; ++k)
            {
                if
            }
        }


    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }

}
#include <stdio.h>
#include <queue>
#include <utility>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 200
using namespace std;

int check[MAX][MAX];
int map[MAX][MAX];
int time_table[MAX][MAX];
queue<pair<int,int> > q;
queue<pair<int,int> > init_q;
vector<int> v;

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    
    memset(check, 0, sizeof(check));
    memset(map, 0, sizeof(map));
    memset(time_table, 0, sizeof(time_table));
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    //searching initial cheeses.
    for(int i = 0; i < n; ++i)
    {
        if(i == 0 || i == n-1)
        {
            for(int j = 0; j < m; ++j)
            {
                if(map[i][j] == 0){
                    init_q.push(make_pair(i,j));
                    break;
                }
            }
        }else{
            if(map[i][0] == 0)
            {
                init_q.push(make_pair(i,0));
                break;
            }
            else if(map[i][m-1] == 0)
            {
                init_q.push(make_pair(i,m-1));
                break;
            }
        }
    }
    
    while(!init_q.empty())
    {
        int curr_n = init_q.front().first;
        int curr_m = init_q.front().second;
        init_q.pop();
        
        int next_n = curr_n + 1;
        int next_m = curr_m;
        if(next_n < n && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            check[next_n][next_m] = 1;
            init_q.push(make_pair(next_n, next_m));
        }
        
        next_n = curr_n - 1;
        next_m = curr_m;
        if(next_n >= 0 && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            check[next_n][next_m] = 1;
            init_q.push(make_pair(next_n, next_m));
        }
        
        next_n = curr_n;
        next_m = curr_m + 1;
        if(next_m < m && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            check[next_n][next_m] = 1;
            init_q.push(make_pair(next_n, next_m));
        }
        
        
        next_n = curr_n;
        next_m = curr_m - 1;
        if(next_m >= 0 && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            check[next_n][next_m] = 1;
            init_q.push(make_pair(next_n, next_m));
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(map[i][j] == 0 && check[i][j] == 1)
            {
                if((i-1 >= 0 && map[i-1][j] == 1)
                   || (i+1 <  n && map[i+1][j] == 1)
                   || (j-1 >= 0 && map[i][j-1] == 1)
                   || (j+1 <  n && map[i][j+1] == 1))
                {
                    q.push(make_pair(i,j));
                }
            }
        }
    }
    ////
    printf("%d\n",q.size());
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            printf("%d ", check[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    ////
    
    int max = 0;
    while(!q.empty())
    {
        int curr_n = q.front().first;
        int curr_m = q.front().second;
        q.pop();
        
        int next_n = curr_n + 1;
        int next_m = curr_m;
        if(next_n < n && check[next_n][next_m] == 0 && map[next_n][next_m] == 1)
        {
            check[next_n][next_m] = 2;
            time_table[next_n][next_m] = time_table[curr_n][curr_m] + 1;
            q.push(make_pair(next_n, next_m));
            if(max < time_table[next_n][next_m])
            {
                max = time_table[next_n][next_m];
                v.push_back(max);
            }
        }
        if(next_n < n && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            q.push(make_pair(next_n, next_m));
        }
        
        next_n = curr_n - 1;
        next_m = curr_m;
        if(next_n >= 0 && check[next_n][next_m] == 0 && map[next_n][next_m] == 1)
        {
            check[next_n][next_m] = 2;
            time_table[next_n][next_m] = time_table[curr_n][curr_m] + 1;
            q.push(make_pair(next_n, next_m));
            if(max < time_table[next_n][next_m])
            {
                max = time_table[next_n][next_m];
                v.push_back(max);
            }
        }
        if(next_n < n && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            q.push(make_pair(next_n, next_m));
        }
        
        next_n = curr_n;
        next_m = curr_m + 1;
        if(next_m < m && check[next_n][next_m] == 0 && map[next_n][next_m] == 1)
        {
            check[next_n][next_m] = 2;
            time_table[next_n][next_m] = time_table[curr_n][curr_m] + 1;
            q.push(make_pair(next_n, next_m));
            if(max < time_table[next_n][next_m])
            {
                max = time_table[next_n][next_m];
                v.push_back(max);
            }
        }
        if(next_n < n && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            q.push(make_pair(next_n, next_m));
        }
        
        next_n = curr_n;
        next_m = curr_m - 1;
        if(next_m >= 0 && check[next_n][next_m] == 0 && map[next_n][next_m] == 1)
        {
            check[next_n][next_m] = 2;
            time_table[next_n][next_m] = time_table[curr_n][curr_m] + 1;
            q.push(make_pair(next_n, next_m));
            if(max < time_table[next_n][next_m])
            {
                max = time_table[next_n][next_m];
                v.push_back(max);
            }
        }
        if(next_n < n && check[next_n][next_m] == 0 && map[next_n][next_m] == 0)
        {
            q.push(make_pair(next_n, next_m));
        }
    }
    
    
    
    sort(v.begin(), v.end());
    
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(time_table[i][j] == v[v.size()-2])
                count++;
        }
    }
    
    ////
    printf("check table\n");
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            printf("%d ", check[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    ////
    
    ////
    printf("time table\n");
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            printf("%d ", time_table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    ////
    
    printf("%d\n%d\n", v[v.size()-1], count);
    
    return 0;
}

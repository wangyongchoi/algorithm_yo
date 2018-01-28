#include <cstdio>
#define INF 2147483647
#define MAX 1005
int n,m,start,end,min = INF;
int map[MAX][MAX];
int dist[MAX];
bool check[MAX];
int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            map[i][j] = INF;
        }
        dist[i] = INF;
        check[i] = false;
    }

    for(int i = 1; i <= m; ++i)
    {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        if(map[from][to] > weight)
            map[from][to] = weight;
    }
    scanf("%d %d", &start, &end);
    dist[start] = 0;
    int node = 0;
    for(int i = 1; i <= n; ++i)
    {
        min = INF;
        for(int j = 1; j <= n; ++j)
        {
            if(!check[j] && dist[j] < min)
            {
                min = dist[j];
                node = j;
            }
        }
        check[node] = true;
        for(int j = 1; j <= n; ++j)
        {
            if(dist[j] > dist[node] + map[node][j] && map[node][j] != min)
            {
                dist[j] = dist[node] + map[node][j];
            }
        } 
    }
    printf("%d\n",dist[end]);
    return 0;
}
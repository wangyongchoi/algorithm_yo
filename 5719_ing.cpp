#include <cstdio>
#include <queue>
#include <vector>
#define MAX 501
#define INF 2147483647
using namespace std;
int n,m,s,d,min_cost = INF;
vector<pair<int, int> > map[MAX];
bool min_path[MAX][MAX];
int dist[MAX];

bool dfs(int curr_cost, int curr_node, vector<bool> check)
{
    check[curr_node] = true;
    if(min_cost < curr_cost)
        return false;
    if(curr_node == d && curr_cost == min_cost)
        return true;
    
    bool ret = false;
    for(int i = 0; i < map[curr_node].size(); ++i)
    {
        int next_cost = map[curr_node][i].second;
        int next_node = map[curr_node][i].first;
        if(check[next_node] == false && dfs(next_node, curr_cost + next_cost, check))
        {
            min_path[curr_node][next_node] = true;
            ret = true;
        }
    }
    return true;
}

int dijkstra(int from, int to)
{
    priority_queue<pair<int, int> > pq;
    int dist[MAX];
    for(int i = 0 ; i < MAX; ++i)
        dist[i] = INF;
    dist[from] = 0;
    pq.push(make_pair(0, from));

    while(!pq.empty())
    {
        int curr_cost = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_cost != dist[curr_node])
            continue;
        for(int i = 0; i < map[curr_node].size(); ++i)
        {
            int next_cost = map[curr_node][i].second;
            int next_node = map[curr_node][i].first;
            if(dist[next_node] > curr_cost + next_cost)
            {
                dist[next_node] = curr_cost + next_cost;
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }
    }
    return dist[to];
}

void print_map()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            printf("%2d", min_path[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            return 0;
        scanf("%d %d", &s, &d);
        int u, v, p;
        for(int i = 0 ; i < m; ++i)
        {
            scanf("%d %d %d", &u, &v, &p);
            map[u].push_back(make_pair(v, p));
        }
        vector<bool> check(n);
        vector<vector<bool> >(n,vector<bool>(n,false));
        min_cost = dijkstra(s, d);
        printf("%d\n", min_cost);
        print_map();
        dfs(s, 0, check);
        print_map();
    }
}
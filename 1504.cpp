#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define MAX 801
#define INF 2147483647
using namespace std;
int n,e,node1,node2;
long long int res;
vector<pair<int, int> > map[MAX];
long long int dijkstra(int from, int to)
{
    priority_queue<pair<int, int> > pq;
    long long int dist[MAX];
    for(int i = 0 ; i < MAX; ++i)
        dist[i] = INF;
    dist[from] = 0;
    pq.push(make_pair(0, from));

    while(!pq.empty())
    {
        long long int curr_cost = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_cost != dist[curr_node])
            continue;
        for(int i = 0; i < map[curr_node].size(); ++i)
        {
            long long int next_cost = map[curr_node][i].second;
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
int main()
{
    scanf("%d %d", &n, &e);
    for(int i = 0; i < e; ++i)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }
    scanf("%d %d", &node1, &node2);

    //1->noe1->node2->n
    long long int res1 = dijkstra(1,node1) + dijkstra(node1,node2) + dijkstra(node2, n);
    //1->node2->node1->n
    long long int res2 = dijkstra(1,node2) + dijkstra(node2,node1) + dijkstra(node1, n);
    if(res1 >= res2)
        res = res2;
    else
        res = res1;
    if(res > INF)
        res = -1;
    printf("%lld\n", res);
    return 0;
}
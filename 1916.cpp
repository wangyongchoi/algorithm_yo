#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1001
#define INF 2147483647
using namespace std;
int n,m,start,dest;
vector<pair<int, int> > v[MAX];
priority_queue<pair<int, int> > pq;
int dist[MAX];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1 ; i <= n; ++i)
        dist[i] = INF;
    for(int i = 0 ; i < m; ++i)
    {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        v[from].push_back(make_pair(to, cost));
    }
    scanf("%d %d", &start, &dest);

    dist[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(cost > dist[curr])
            continue;
        for(int i = 0 ; i < v[curr].size(); ++i)
        {
            int temp_cost = cost + v[curr][i].second;
            int temp_node = v[curr][i].first;
            if(temp_cost < dist[temp_node])
            {
                dist[temp_node] = temp_cost;
                pq.push(make_pair(temp_cost, temp_node));
            }
        }
    }
    printf("%d\n", dist[dest]);
    return 0;
}

#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#define MAX 20001
#define INF 2147483647
using namespace std;
int V,E,start;
vector<pair<int, int> > map[MAX];
priority_queue<pair<int, int> > pq;
int dist[MAX];
int main()
{
    scanf("%d %d %d", &V, &E, &start);
    for(int i = 1 ; i <= V; ++i)
        dist[i] = INF;
    for(int i = 0 ; i < E; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        map[u].push_back(make_pair(v,w));
    }

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty())
    {
        //원소에 -1 곱해서 min heap으로 활용.
        int curr_cost = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
       
        if(curr_cost > dist[curr_node])
            continue;
        for(int i = 0 ; i < map[curr_node].size(); ++i)
        {
            int next_cost = map[curr_node][i].second;
            int next_node = map[curr_node][i].first;
            if(curr_cost + next_cost < dist[next_node])
            {
                dist[next_node] = curr_cost + next_cost;
                //min heap으로 활용하기 위함.
                pq.push(make_pair(-dist[next_node], next_node));
            }
        }
    }

    for(int i = 1; i <= V; ++i)
    {
        if(dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
    return 0;
}
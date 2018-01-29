#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define MAX 1001
#define INF 2147483647
using namespace std;
int n,m,x;
vector<pair<int, int> > map_go[MAX];
vector<pair<int, int> > map_come[MAX];
priority_queue<pair<int, int> > pq;
int dist_go[MAX];
int dist_come[MAX];
int main()
{
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 0; i < m; ++i)
    {
        int from, to, time;
        scanf("%d %d %d", &from, &to, &time);
        map_come[from].push_back(make_pair(to, time));
        map_go[to].push_back(make_pair(from, time));
    }
    
    for(int i = 1; i <= n; ++i)
    {
        dist_come[i] = INF;
        dist_go[i] = INF;
    }
    
    dist_come[x] = 0;
    pq.push(make_pair(0, x));
    
    while(!pq.empty())
    {
        int curr_time = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_time != dist_come[curr_node])
            continue;
        for(int i = 0; i < map_come[curr_node].size(); ++i)
        {
            int next_time = map_come[curr_node][i].first;
            int next_node = map_come[curr_node][i].second;
            if(dist_come[next_node] > curr_time + next_time)
            {
                dist_come[next_node] = curr_time + next_time;
                pq.push(make_pair(-dist_come[next_node], next_node));
            }
        }
    }

    dist_go[x] = 0;
    pq.push(make_pair(0, x));
    
    while(!pq.empty())
    {
        int curr_time = -pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_time != dist_go[curr_node])
            continue;
        for(int i = 0 ; i < map_go[curr_node].size(); ++i)
        {
            int next_time = map_go[curr_node][i].first;
            int next_node = map_go[curr_node][i].second;
            if(dist_go[next_node] > curr_time + next_time)
            {
                dist_go[next_node] = curr_time + next_time;
                pq.push(make_pair(-dist_go[next_node], next_node));
            }
        }
    }

    int max = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(dist_go[i] + dist_come[i] > max)
            max = dist_go[i] + dist_come[i];
    }
    printf("%d\n", max);
    return 0;
}
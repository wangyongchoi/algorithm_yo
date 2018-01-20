//union find를 이용하여 merge 수행 후 root가 같은지 비교.
#include <cstdio>
#define MAX 200
int n,m;
int parents[MAX];
int find(int u)
{
    if(u == parents[u])
        return u;
    return parents[u] = find(parents[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    parents[v] = u;
}

int main()
{
    scanf("%d %d", &n, &m);
    //init
    for(int i = 1; i <= n; ++i)
        parents[i] = i;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            int node;
            scanf("%d", &node);
            if(node == 1)
                merge(i, j);
        }
    }

    int from;
    scanf("%d", &from);
    from = find(from);
    for(int i = 1; i < m; ++i)
    {
        int curr_city;
        scanf("%d", &curr_city);
        curr_city = find(curr_city);
        if(from != curr_city)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
#include <cstdio>
#define MAX 1000000
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

    parents[u] = v;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < MAX; ++i)
        parents[i] = i;
    while(m--)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0)
            merge(b,c);
        else{
            if(find(b) == find(c))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
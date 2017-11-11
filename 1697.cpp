#include <stdio.h>
#include <queue>
#define MAX 200001
using namespace std;
queue<int> q;
bool check[MAX] = {false,};
int dist[MAX] = {0, };
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	q.push(n);
    check[n] = true;
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
        
		int next = curr - 1;
        if(next >= 0)
        {
            if(check[next] == false)
            {
                q.push(next);
                dist[next] = dist[curr] + 1;
                check[next] = true;
            }
        }
        
        next = curr + 1;
        if(next < MAX)
        {
            if(check[next] == false)
            {
                q.push(next);
                dist[next] = dist[curr] + 1;
                check[next] = true;
            }
        }
        
        next = curr * 2;
        if(next < MAX)
        {
            if(check[next] == false)
            {
                q.push(next);
                dist[next] = dist[curr] + 1;
                check[next] = true;
            }
        }
	}

	printf("%d\n", dist[k]);
	return 0;
}

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 100

using namespace std;
int check[MAX];

int main()
{
	int n, m, from, to;
	scanf("%d %d %d %d", &n, &from, &to, &m);
	
	vector<int> adj[n+1];
	while(m--)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	//test
	for(int i = 0; i < n+1; ++i)
	{
		printf("[%d] ", i);
		for(int j = 0; j < adj[i].size(); ++j)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}

	//bfs
	int count = 0;
	queue<int> q;
	q.push(from);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		for(int i = 0 ; i < adj[curr].size(); ++i)
		{
			int next = adj[curr][i];
			if(check[next] == false)
			{
				count++;
				check[next] = true;
			}
		}
	}	

	printf("%d\n",count);
	return 0;
}


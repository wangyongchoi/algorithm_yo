#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>

#define MAX 1000
using namespace std;
bool check[MAX][MAX];
vector<int> adj[MAX];
queue<int> q;
int box[MAX][MAX];

int main()
{
	int m,n;
	scanf("%d %d", &m, &n);
	for(int i = 0 ; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%d",&box[i][j]);
		}
	}


}

#include <stdio.h>
#include <queue>
#include <string>
#define MAX 10000
using namespace std;
bool primes[MAX];
int change(int curr, int i, int j)
{
	if(i == 0 && j == 0)
		return -1;
	string s = to_string(curr);
	s[i] = j + '0';
	return stoi(s);
}

int main()
{
	for(int i = 2; i < MAX; ++i)
		primes[i] = true;

	for(int i = 2; i * i < MAX; ++i)
	{
		if(primes[i] == false)
			continue;
		for(int j = i*2; j < MAX; j+=i)
			primes[j] = false;
	}

	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		queue<int> q;
		bool check[MAX] = {0, };
		int dist[MAX] = {0, };
		q.push(a);
		check[a] = true;
		dist[a] = 0;
		
		while(!q.empty())
		{
			int curr = q.front();
			q.pop();
			
			for(int i = 0; i < 4; ++i)
			{
				for(int j = 0; j < 10; ++j)
				{
					int next = change(curr, i, j);
					if(next != -1)
					{
						if(primes[next] && check[next] == false)
						{
							q.push(next);
							dist[next] = dist[curr] + 1;
							check[next] = true;
						}
					}
				}
			}
		}
		printf("%d\n", dist[b]);
	}
}


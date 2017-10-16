/*
BFS 문제로, queue를 사용하며, 최단경로 문제에 많이 이용된다.
DFS와 달리 거리를 기준으로 순서대로 방문.
이 문제의 경우 D,S,L,R operation의 갯수가 거리라고 할 수 있다.
1. 처음 시작점을 queue에 push
2. 전체 while loop를 queue가 빌 때까지
3. queue에서 한개꺼내고 operation에 맞게 next를 계산하고 next 위치에 from과 how를 할당.
BFS 문제의 경우 크게 보면 배열을 전부 채운다고 생각하면 좋을 것 같다.
배열이 모두 true로 채워지면 queue가 비워져 문제가 종료된다.
*/
#include <stdio.h>
#include <queue>
#include <string.h>
#define MAX 20000
using namespace std;
bool check[MAX+1];
int from[MAX+1];
char how[MAX+1];

void print(int start, int end)
{
	if(start == end)
		return;
	print(start, from[end]);
	printf("%c", how[end]);
	return;
}

void go(int a, int b)
{
	memset(check, false, sizeof(check));
	memset(from, 0, sizeof(from));
	memset(how, 0, sizeof(how));
	queue<int> q;
	q.push(a);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		//D
		int next = (curr*2)%10000;
		if(check[next] == false)
		{
			check[next] = true;
			q.push(next);
			from[next] = curr;
			how[next] = 'D';
		}
		
		//S
		next = curr - 1;
		if(next == -1)
			next = 9999;
		if(check[next] == false)
		{
			check[next] = true;
			q.push(next);
			from[next] = curr;
			how[next] = 'S';
		}

		//L
		next = (curr%1000)*10 + curr/1000;
		if(check[next] == false)
		{
			check[next] = true;
			q.push(next);
			from[next] = curr;
			how[next] = 'L';
		}

		//R
		next = curr/10 + (curr%10) * 1000;
		if(check[next] == false)
		{
			check[next] = true;
			q.push(next);
			from[next] = curr;
			how[next] = 'R';
		}

	}
	
	print(a,b);
	printf("\n");
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a, b;
		scanf("%d %d",&a, &b);
		go(a,b);
	}
	return 0;
}

#include <stdio.h>
#include <queue>
#define MAX 10000
using namespace std;
queue<int> q;
int how[MAX+1] = {0,};
int from[MAX+1] = {0,};
bool check[MAX+1] = {false, };
int cnt_a = 0, cnt_b = 0, cnt_c = 0;
void check_count(int start, int end)
{
	if(start == end)
		return;
	check_count(start, from[end]);
	int curr = how[end];
	if(curr == 1)
		cnt_a++;
	else if(curr == 2)
		cnt_b++;
	else if(curr == 3)
		cnt_c++;
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	q.push(0);
	
	while(!q.empty())
	{
		int curr_t = q.front();
		q.pop();

		//a
		int next_t = curr_t + 5*60;
		if(next_t <= t && !check[next_t])
		{
			q.push(next_t);
			how[next_t] = 1;
			from[next_t] = curr_t;
			check[next_t] = true;
		}

		//b
		next_t = curr_t + 60;
		if(next_t <= t && !check[next_t])
		{
			q.push(next_t);
			how[next_t] = 2;
			from[next_t] = curr_t;
			check[next_t] = true;
		}

		//c
		next_t = curr_t + 10;
		if(next_t <= t && !check[next_t])
		{
			q.push(next_t);
			how[next_t] = 3;
			from[next_t] = curr_t;
			check[next_t] = true;
		}
	}
	check_count(0, t);
	if(t < 10 || t%10 != 0)
		printf("-1\n");
	else
		printf("%d %d %d\n", cnt_a, cnt_b, cnt_c);
	return 0;
}

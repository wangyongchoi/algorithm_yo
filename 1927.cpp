/*
min heap을 만들어서 풀 수 있다.
*/
#include <stdio.h>
#include <functional>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > min_heap;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int temp;
		scanf("%d", &temp);
		if(min_heap.empty() && temp == 0)
		{
			printf("0\n");
		}
		else if(!min_heap.empty() && temp == 0)
		{
			printf("%d\n",min_heap.top());
			min_heap.pop();
		}
		else
		{
			min_heap.push(temp);
		}
	}
	return 0;
}

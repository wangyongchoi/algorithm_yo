/*
median 값을 구하기 위해서 max heap과 min heap을 사용한다.
이 문제는 N이 100000 이므로, 입력받아 quick sort(nlogn)로 정렬하는 방법으로는 구할 수 없다.
max heap과 min heap을 구성하고, 처음과 두 heap의 사이즈가 같을때에는 max heap에 push,
나머지는 min heap에 push 하면서 max heap의 top값이 min heap의 top 값보다 커지면 서로의 top값을
pop해서 반대의 heap에 push하는 방법을 취하면 max heap의 top 값에 항상 중앙값을 유지할 수 있다.
*/

#include <stdio.h>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int temp;
		scanf("%d", &temp);
		if(max_heap.empty() || max_heap.size() == min_heap.size())
		{
			max_heap.push(temp);
		}else{
			min_heap.push(temp);
		}
		if(!min_heap.empty() && !max_heap.empty())
		{
			if(max_heap.top() >= min_heap.top())
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}

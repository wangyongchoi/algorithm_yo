/*
단순한 문제로 보았는데, 돈을 인출하는데 최소의 시간을 가지려면
각각의 사람들마다 Turn-arround Time을 오름차순으로 정렬하고
각각의 사람들의 waiting time + turn-arround time을 계산하였다.
*/
#include <stdio.h>
#include <algorithm>
#include <functional>
#define MAX 1001
using namespace std;
int arr[MAX];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+n, less<int>());
	
	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			sum += arr[j];
		}
	}

	printf("%d\n",sum);
	return 0;
}

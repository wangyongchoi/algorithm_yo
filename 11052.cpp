#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> d(n+1);
	vector<int> p(n+1);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		//d[i] 하나를 구하기 위함.
		for(int j = 1; j <= i; ++j) 
		{
			d[i] = max(d[i], d[i-j] + p[j]);
		}
	}
	printf("%d\n", d[n]);
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(10000);
	for(int i = 0; i < n; ++i)
	{
		int pos;
		scanf("%d", &pos);
		v[pos]++;
	}
	for(int i = 1; i <= 10000; ++i)
	{
		if(v[i] != 0)
		{
			while(v[i]--)
				printf("%d\n", i);
		}
	}
	return 0;
}

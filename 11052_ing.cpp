#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#define MAX 1000
using namespace std;
pair<double,int> unit_costs[MAX+1];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n; ++i)
	{
		int price;
		scanf("%d",&price); 
		unit_costs[i] = make_pair((double)price / (i+1), i+1);
	}
	sort(unit_costs, unit_costs+n);
	reverse(unit_costs, unit_costs+n);
	for(int i = 0 ; i < n; ++i)
	{
		printf("%lf %d\n", unit_costs[i].first, unit_costs[i].second);
	}

	int income = 0;
	for(int i = 0; i < n; ++i)
	{
		if(n == 0)
			break;
		income += (n/unit_costs[i].second) * (unit_costs[i].second*unit_costs[i].first);
		n%=unit_costs[i].second;
	}
	printf("%d\n", income);
	return 0;
}

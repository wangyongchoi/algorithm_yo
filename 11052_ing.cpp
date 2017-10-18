#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#define MAX 1000
using namespace std;
pair<double,int> unit_costs[MAX+1];
bool compare(const pair<double, int>&i, const pair<double, int>&j)
{
	if(i.first == j.first)
		return i.second < j.second;
	else
    	return i.first > j.first;
}

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
	sort(unit_costs, unit_costs+n, compare);

	int income = 0;
	int i = 0;
	int items = n;
	while(1)
	{
		income += (items/unit_costs[i].second) * (unit_costs[i].second*unit_costs[i].first);
		items%=unit_costs[i].second;
		if(items == 0)
			break;
		if(++i == n)
			i = 0;
	}

	printf("%d\n", income);
	return 0;
}

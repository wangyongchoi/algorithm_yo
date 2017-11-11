#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int go(vector<int> &a)
{
	int sum = 0;
	for(int i = 1; i < a.size(); ++i)
	{
		sum += abs(a[i] - a[i-1]);
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; ++i)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;

	do{
		int temp = go(a);
		ans = max(ans, temp);
	}while(next_permutation(a.begin(), a.end()));
	
	cout << ans << endl;

	return 0;
}

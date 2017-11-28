#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);	
	for(int i = 0 ; i < n; ++i)
	{
		v[i] = i+1;
	}
	int t;
	cin >> t;		
	if(t == 1)
	{
		int s;
		cin >> s;
		while(--s)
		{
			next_permutation(v.begin(), v.end());
		}
		for(int i = 0; i < n; ++i)
		{
			cout << v[i] << " ";
		}
		cout << '\n';

	}else{
		vector<int> v2(n);
		for(int i = 0 ; i < n; ++i)
		{
			cin >> v2[i];
		}
		int cnt = 0;
		int found = 0;
		while(1)
		{
			cnt++;
			if(!next_permutation(v.begin(), v.end()) || found)
				break;
			for(int i = 0 ; i < n; ++i)
			{
				if(v[i] != v2[i])
				{
					break;
				}
				if(i == n-1)
					found = 1;
			}
		}
		cout << cnt << endl;
	}
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int e;
		cin >> e;
		v.push_back(e);
	}
	if(prev_permutation(v.begin(), v.end()))
	{
		for(int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;
	}else{
		cout << "-1" << endl;
	}
}

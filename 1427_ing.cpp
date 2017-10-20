#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> v;

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); ++i)
	{
		v.push_back(atoi(s[i]));
	}
	sort(v.begin(), v.end());
	for(int i = 0 ; v.size(); ++i)
		printf("%d",v[i]);
	printf("\n");
	return 0;
}

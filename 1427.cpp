/*
그냥..
*/
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
vector<int> v;

int main()
{
	int length = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
	{
		v.push_back(s[i] - '0');
		length++;
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0 ; i < length; ++i)
		printf("%d",v[i]);
	printf("\n");
	return 0;
}

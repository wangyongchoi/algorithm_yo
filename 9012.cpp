#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		int cnt = 0;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '(')
				cnt++;
			else
				cnt--;
			if(cnt < 0)
			{
				break;
			}
		}
		if(cnt == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

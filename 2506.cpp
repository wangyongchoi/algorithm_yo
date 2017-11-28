#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0,extra = 0;
	cin >> n;
	for(int i = 0 ; i < n; ++i)
	{
		int score;
		cin >> score;
		if(score == 0)
			extra = 0;
		else{
			sum += score + extra++;
		}
	}
	cout << sum << endl;
}


#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0;
	cin >> n;
	int loop = n;
	while(loop--)
	{
		int v;
		cin >> v;
		sum += v;
	}
	if(sum > n/2)
		cout << "Junhee is cute!" << endl;
	else
		cout << "Junhee is not cute!" << endl;
}

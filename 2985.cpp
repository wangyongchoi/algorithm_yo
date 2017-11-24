#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	if(a + b == c)
	{
        cout << a << "+" << b << "=" << c << endl;
	}else if(a-b == c)
	{
        cout << a << "-" << b << "=" << c << endl;

	}else if(a*b == c)
	{
        cout << a << "*" << b << "=" << c << endl;

	}else if((double)a/b == (double)c)
    {
        cout << a << "/" << b << "=" << c << endl;
    }else{
    
        if(a == b + c)
        {
            cout << a << "=" << b << "+" << c << endl;
        }else if(a == b - c)
        {
            cout << a << "=" << b << "-" << c << endl;
            
        }else if(a == b * c)
        {
            cout << a << "=" << b << "*" << c << endl;
            
        }else if((double)a == b/(double)c)
        {
            cout << a << "=" << b << "/" << c << endl;
        }
    }
	return 0;
}

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
    int is_java_type = 0;
	string str;
	char ch;
	int upper = 0;
	cin >> str;
    
    if(str[0] == '_' || isupper(str[0]) || str[str.length()-1] == '_')
    {
        cout << "Error!" << endl;
        return 0;
    }
    for(int i = 1; i < str.length(); ++i)
    {
        if(str[i] == '_')
        {
            is_java_type = 1;
            if(i+1 < str.length() && str[i+1] == '_')
            {
                cout << "Error!" << endl;
                return 0;
            }
        }
        if(is_java_type && isupper(str[i]))
        {
            cout << "Error!" << endl;
            return 0;
        }
    }
    
    if(is_java_type)
    {
        for(int i = 0; i < str.length(); ++i)
        {
            ch = str[i];
            if(ch == '_')
            {
                upper = 1;
                continue;
            }
            if(upper)
                cout << (char)(ch-32);
            else
                cout << ch;
            upper = 0;
        }
        cout << endl;
    }else{
        
        if(isupper(str[0]))
            cout << (char)(str[0] + 32);
        else
            cout << str[0];
        for(int i = 1; i < str.length(); ++i)
        {
            ch = str[i];
            if(isupper(ch))
            {
                cout << "_";
                ch = ch + 32;
            }
            cout << ch;
        }
        cout << endl;
    }
}	

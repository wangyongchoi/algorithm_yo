#include <iostream>
#include <string>
using namespace std;
int res[82] = {0, };
int cnt = 0;
int a[81] = {0, };
int b[81] = {0, };
int main()
{
    for(int i = 0 ; i <= 81; ++i)
    {
        res[i] = 0;
    }
    int a_len = 0;
    int b_len = 0;
    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 0 ; i < str1.size(); ++i)
    {
        a[i] = str1.at(str1.size() - 1 - i) - '0';
        a_len++;
    }
    for(int i = 0 ; i < str2.size(); ++i)
    {
        b[i] = str2.at(str2.size() - 1 - i) - '0';
        b_len++;
    }
    int len = 0;
    
    if(a_len > b_len)
    {
        len = a_len;
    }else
        len = b_len;
    
    int carry = 0;
    for(int i = 0; i < len; ++i)
    {
        int num = a[i] + b[i] + carry;
        carry = 0;
        if(num >= 2)
        {
            carry = 1;
            num -= 2;
        }
        res[cnt++] = num;
    }
    if(carry == 1)
        res[cnt++] = carry;
    
    int ok_print = 0;
    for(int i = cnt-1; i >= 0; --i)
    {
        if(res[i] == 1)
            ok_print = 1;
        if(ok_print)
            cout << res[i];
    }
    if(ok_print == 0)
        cout << "0";
    cout << endl;
}

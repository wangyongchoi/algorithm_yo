#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}

vector<string> prefixToInfix(vector<string> prefixes)
{
    vector<string> infixes;
    int count = prefixes.size();
    for(int i = 0; i < count; ++i)
    {
        stack<string> stk;
        string prefix = prefixes[i];
        int length = prefix.length();
        for(int j = length-1; j >= 0; --j)
        {
            if(isOperator(prefix[j]))
            {
                string s1 = stk.top(); stk.pop();
                string s2 = stk.top(); stk.pop();
                string s3 = "("+s1+prefix[j]+s2+")";
                stk.push(s3);
            }else{
                stk.push(string(1, prefix[j]));
            }
        }
        infixes.push_back(stk.top());
    }
    return infixes;
}

int main()
{
    vector<string> res;
    int prefixes_size = 0;
    cin >> prefixes_size;
    vector<string> prefixes;
    for(int i = 0 ; i < prefixes_size; i++){
        string prefixes_item;
        cin >> prefixes_item;
        prefixes.push_back(prefixes_item);
    }
    res = prefixToInfix(prefixes);
    for(int res_i = 0; res_i < res.size(); res_i++)
    {
        cout << res[res_i] << endl;
    }
    return 0;
}
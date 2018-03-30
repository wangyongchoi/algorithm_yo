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

vector<string> postfixToInfix(vector<string> postfixes)
{
    vector<string> Infixes;
    int count = postfixes.size();
    for(int i = 0; i < count; ++i)
    {
        stack<string> stk;
        string postfix = postfixes[i];
        int length = postfix.length();
        for(int j = 0; j < length; ++j)
        {
            if(isOperator(postfix[j]))
            {
                string s1 = stk.top(); stk.pop();
                string s2 = stk.top(); stk.pop();
                string infix = "("+s2+postfix[j]+s1+")";
                stk.push(infix);
            }else{
                stk.push(string(1, postfix[j]));
            }
        }
        Infixes.push_back(stk.top());
    }
    return Infixes;
}

int main()
{
    vector<string> res;
    int postfixes_size = 0;
    cin >> postfixes_size;
    vector<string> postfixes;
    for(int i = 0 ; i < postfixes_size; i++){
        string postfixes_item;
        cin >> postfixes_item;
        postfixes.push_back(postfixes_item);
    }
    res = postfixToInfix(postfixes);
    for(int res_i = 0; res_i < res.size(); res_i++)
    {
        cout << res[res_i] << endl;
    }
    return 0;
}
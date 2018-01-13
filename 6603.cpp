#include <iostream>
#include <cstdio>
#include <string>
#define MAX 13
using namespace std;

int k;
string ans[13];

void dfs(int index, string str, int count)
{
    if(count == 6)
    {
        for(int i = 0 ; i < str.size(); ++i)
        {
            cout << str[i];
        }
        printf("\n");
        return;
    }

    for(int i = index; i < k; ++i)
    {
        dfs(i + 1, str + ans[i] + ' ', count+1);
    }

}
int main()
{
    while(1)
    {
        scanf("%d", &k);
        if(k == 0)
            break;
        for(int i = 0 ; i < k; ++i)
        {
            cin >> ans[i];
        }
        dfs(0,"", 0);
        printf("\n");
    }
    return 0;
}
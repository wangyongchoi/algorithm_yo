/*
max heap을 사용해서 풀 수 있다.
*/
#include <stdio.h>
#include <functional>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > max_heap;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int temp;
        scanf("%d", &temp);
        if(max_heap.empty() && temp == 0)
        {
            printf("0\n");
        }
        else if(!max_heap.empty() && temp == 0)
        {
            printf("%d\n",max_heap.top());
            max_heap.pop();
        }
        else
        {
            max_heap.push(temp);
        }
    }
    return 0;
}

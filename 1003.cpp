#include <stdio.h>
int cnt_zero = 0;
int cnt_one = 0;
long long fibo(int n)
{
    if(n == 0)
    {
        cnt_zero++;
        return n;
    }else if(n == 1)
    {
        cnt_one++;
        return n;
    }else{
        return fibo(n-1) + fibo(n-2);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        cnt_zero = 0;
        cnt_one = 0;
        int temp;
        scanf("%d", &temp);
        fibo(temp);
        printf("%d %d\n", cnt_zero, cnt_one);
    }
    return 0;
}

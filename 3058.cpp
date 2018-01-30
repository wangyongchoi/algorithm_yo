#include <cstdio>
int t;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int sum = 0;
        int min = 2147483647;
        for(int i = 0 ; i < 7; ++i)
        {
            int temp;
            scanf("%d", &temp);
            if(temp%2==0)
            {
                sum += temp;
                min = min>temp? temp: min;
            }
        }
        printf("%d %d\n", sum, min);
    }
    return 0;
}
#include <cstdio>
#define MAX 1000000
int students[MAX];
int n,b,c;
long res;
void go()
{
    for(int i = 0; i < n; ++i)
    {
        res+=1;
        if(students[i]-b > 0)
            students[i] -= b;
        else
            students[i] = 0;
        res+=students[i]/c;
        students[i]%=c;
        if(students[i] > 0)
            res+=1;
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &students[i]);
    }
    scanf("%d %d", &b, &c);
    go();
    printf("%ld\n", res);
    return 0;
}
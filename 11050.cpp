#include <stdio.h>
int combination(int a, int b)
{
    int mo = 1;
    int ja = 1;
    int loop = b;
    for(int i = 0 ; i < loop; ++i)
    {
        mo *= a--;
        ja *= b--;
    }
    
    return mo / ja;
}
int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", combination(a,b));
}

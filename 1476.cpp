#include <stdio.h>
int main()
{
    int e,s,m;
    scanf("%d %d %d", &e, &s, &m);
    
    int curr_e = 1, curr_s = 1, curr_m = 1;
    for(int i = 1;; ++i)
    {
        if(e == curr_e && s == curr_s && m == curr_m)
        {
            printf("%d\n", i);
            return 0;
        }
        curr_e++;
        curr_s++;
        curr_m++;
        if(curr_e == 16)
            curr_e = 1;
        if(curr_s == 29)
            curr_s = 1;
        if(curr_m == 20)
            curr_m = 1;
    }
}

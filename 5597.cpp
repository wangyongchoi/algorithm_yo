#include <cstdio>
bool arr[31];
int main()
{
    for(int i = 0; i < 28; ++i)
    {
        int idx;
        scanf("%d", &idx);
        arr[idx] = true;
    }

    for(int i = 1; i <= 30; ++i)
    {
        if(arr[i] == false)
            printf("%d\n", i);
    }
    return 0;
}
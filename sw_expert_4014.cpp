#include <stdio.h>
#include <iostream>
#define MAX 21
using namespace std;
int map[MAX][MAX];
int n, x;
int cnt;
bool acsending[MAX];
bool decsending[MAX];
int arr[MAX];

bool isFlat(int from, int to)
{
    if(from < 0 || to >= n)
        return false;

    for(int i = from; i < to; ++i)
    {
        if(arr[i] != arr[i+1])
            return false;
    }
    return true;
}

bool go(int row, int col, int dir)
{
   
    if(dir == 1) //horizon
    {
        for(int i = 0; i < n; ++i)
        {
            arr[i] = map[row][col+i];
        }
    }else{//vertical
        for(int i = 0; i < n; ++i)
        {
            arr[i] = map[row+i][col];
        }
    }

    //initialize.
    for(int i = 0; i < MAX; ++i)
    {
        acsending[i] = decsending[i] = false;
    }

    //1. 차이 2이상 error
    for(int i = 0; i < n-1; ++i)
    {
        if(abs(arr[i]-arr[i+1]) > 1)
            return false;
    }

    for(int i = 0; i < n-1; ++i)
    {
        
        if(arr[i] == arr[i+1] + 1) //2.decsending
        {
            int from = i+1;
            int to = i+x;
            if(isFlat(from, to))
            {
                for(int j = from; j <= to; ++j)
                {
                    decsending[j] = true;
                }
            }else{
                return false;
            }
        }
        else if(arr[i]+1 == arr[i+1]) //3.acsending
        {
            int from = i-x+1;
            int to = i;
            if(isFlat(from, to))
            {
                for(int j = from; j <= to; ++j)
                {
                    acsending[j] = true;
                }
            }else{
                return false;
            }
        }
    }

    for(int i = 0; i < n; ++i)
    {
        if(acsending[i] && decsending[i])
            return false;
    }

    return true;
}

int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
        cnt = 0;
        scanf("%d %d", &n, &x);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &map[i][j]);
            }
        }
        for(int i = 0 ; i < n; ++i)
        {
            if(go(i, 0, 1))
                cnt++;
            if(go(0, i, 2))
                cnt++;
        }
        printf("#%d %d\n", test_case, cnt);
	}
    
	return 0;
}
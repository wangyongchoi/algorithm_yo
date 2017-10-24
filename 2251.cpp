/*
전부 다 해보면 되는 문제이다.
BFS로 탐색하고, 2차원 배열로 첫번째 물통과 두번째 물통을 check하면
세번째 물통은 알 수 있다. (처음에 물의 양이 정해지기 때문)
*/
#include <stdio.h>
#include <queue>
#include <utility>
#define MAX 201
using namespace std;

bool check[MAX][MAX];
queue<pair<int,int> > q;
bool answers[MAX];

int main()
{	
	memset(check, false, sizeof(check));
	memset(answers, false, sizeof(answers));
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	int total = c;
	
    check[0][0] = true;
	q.push(make_pair(0,0));
    answers[c] = true;
    
	while(!q.empty())
	{
		int curr_a = q.front().first;
		int curr_b = q.front().second;
		int curr_c = total - curr_a - curr_b;
		q.pop();
		
		int next_a = curr_a;
		int next_b = curr_b;
		int next_c = curr_c;
		//a->b
		next_b += next_a;
		next_a = 0;
		if(next_b >= b)
		{
            next_a = next_b - b;
			next_b = b;
		}
		if(check[next_a][next_b] == false)
		{
			check[next_a][next_b] = true;
			q.push(make_pair(next_a, next_b));
			if(next_a == 0)
				answers[next_c] = true;
		}
        
        next_a = curr_a;
        next_b = curr_b;
        next_c = curr_c;
		//a->c
        next_c += next_a;
        next_a = 0;
        if(next_c >= c)
        {
            next_a = next_c - c;
            next_c = c;
        }
        if(check[next_a][next_b] == false)
        {
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
            if(next_a == 0)
                answers[next_c] = true;
        }
        
        next_a = curr_a;
        next_b = curr_b;
        next_c = curr_c;
		//b->c
        next_c += next_b;
        next_b = 0;
        if(next_c >= c)
        {
            next_b = c - next_c;
            next_c = c;
        }
        if(check[next_a][next_b] == false)
        {
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
            if(next_a == 0)
                answers[next_c] = true;
        }

        next_a = curr_a;
        next_b = curr_b;
        next_c = curr_c;
		//b->a
        next_a += next_b;
        next_b = 0;
        if(next_a >= a)
        {
            next_b = next_a - a;
            next_a = a;
        }
        if(check[next_a][next_b] == false)
        {
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
            if(next_a == 0)
                answers[next_c] = true;
        }
        
        next_a = curr_a;
        next_b = curr_b;
        next_c = curr_c;
		//c->a
        next_a += next_c;
        next_c = 0;
        if(next_a >= a)
        {
            next_c = next_a - a;
            next_a = a;
        }
        if(check[next_a][next_b] == false)
        {
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
            if(next_a == 0)
                answers[next_c] = true;
        }
        
        next_a = curr_a;
        next_b = curr_b;
        next_c = curr_c;
		//c->b
        next_b += next_c;
        next_c = 0;
        if(next_b >= b)
        {
            next_c = next_b - b;
            next_b = b;
        }
        if(check[next_a][next_b] == false)
        {
            check[next_a][next_b] = true;
            q.push(make_pair(next_a, next_b));
            if(next_a == 0)
                answers[next_c] = true;
        }
	}

    for(int i = 0; i <= c; ++i)
    {
        if(answers[i] == true)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    
	return 0;
}

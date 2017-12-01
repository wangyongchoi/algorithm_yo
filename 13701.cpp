//메모리 제한이 8MB이므로, 배열을 전부 잡을 수 없고
//비트마스크로 구현해야 하는데 8MB까지 메모리를 잡으려면
//2^20개의 int 배열이 가능하고 2^24까지 수를 받으려면
//5bit를 줄여야한다.
//따라서  1 | 10001
//        1 | 00001
//        1 | 00000
//해당 수는 b[1] 배열에 저장하는 방법으로 구현하면 된다.
//1 | 00000 도 중복체크를 할 수 있는 이유는
//비트 마스킹할 경우 1 << 0을 shift 해도 1로 나타나기 때문이다.
#include <stdio.h>
int b[(1<<20) + 1];
int n;
int index, offset;
int main()
{
	while(scanf("%d", &n) == 1)
	{
		index = n/32;
		offset = n%32;
		if(b[index] & (1 << offset))
			continue;
		printf("%d ", n);
		b[index] += (1 << offset);
	}
}

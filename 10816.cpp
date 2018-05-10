#include <cstdio>
#include <map>
using namespace std;
map<int, int> m;
int main()
{
   int n, temp;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i)
   {
       scanf("%d", &temp);
       m[temp]++;
   }
   scanf("%d", &n);
   for(int i = 0; i < n; ++i)
   {
       scanf("%d", &temp);
       printf("%d ", m[temp]);
   }
   return 0;
}
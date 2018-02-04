#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    float sum = 0.0;
    scanf("%d", &n);
    vector<float> v(n);
    for(int i = 0; i < n; ++i)
        scanf("%f", &v[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i)
    {
        v[i] = v[i]/v[n-1] * 100;
        sum += v[i];
    }
    printf("%.2f\n", sum/n);
    return 0;
}
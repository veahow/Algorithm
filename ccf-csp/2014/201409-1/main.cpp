#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1005;
int arr[MAXN];

using namespace std;

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);

    sort(arr+1, arr+1+n);

    for(int i = 1; i <= n-1; ++i)
        if(abs(arr[i] - arr[i+1]) == 1) cnt++;

    printf("%d\n", cnt);

    return 0;
}

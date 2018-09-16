#include <cstdio>
#include <algorithm>

const int MAXN = 1005;

using namespace std;

int main()
{
    int n, arr[MAXN], dev[MAXN];

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)

        scanf("%d", arr + i);
    for(int i = 1; i <= n-1; ++i)
        dev[i] = abs(arr[i] - arr[i+1]);

    sort(dev+1, dev+n);

    printf("%d\n", dev[n-1]);

    return 0;
}

#include <cstdio>
#include <algorithm>

const int MAXN = 1005;

using namespace std;

int main()
{
    int n, k, arr[MAXN], left = 0, right = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", arr+i);

    sort(arr+1, arr+1+n);

    k = n/2+1;

    for(int i = 1; i <= n; ++i){
        if(arr[k] > arr[i]) left++;
        if(arr[k] < arr[i]) right++;
    }

    if(left == right) printf("%d\n", arr[k]);
    else printf("-1\n");

    return 0;
}

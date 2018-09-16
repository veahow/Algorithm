#include <cstdio>

const int MAXN = 1005;

using namespace std;

int a[MAXN];

int main()
{
    int n, k, w = 0, cnt = 0;
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    for(int i = 1; i <= n; ++i){
        w += a[i];
        if(w >= k){
            w = 0;
            cnt++;
        }
    }
    if(w) cnt++;

    printf("%d\n", cnt);

    return 0;
}

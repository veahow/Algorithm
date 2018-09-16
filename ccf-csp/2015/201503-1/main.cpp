#include <cstdio>

const int MAXN = 1005;
const int MAXM = 1005;
int arr[MAXN][MAXM];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &arr[i][j]);

     for(int i = m; i >= 1; --i){
        for(int j = 1; j <= n; ++j)
            if(j != n) printf("%d ", arr[j][i]);
            else printf("%d\n", arr[j][i]);
    }

    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int k;
    int s;
}Men;

const int MAXN = 5000 + 5;
int n,m;
int num,line,cnt;
Men arr[MAXN];

bool cmp(Men a,Men b)
{
    if(a.s == b.s) return a.k < b.k;
    return a.s > b.s;
}
int main()
{
    scanf("%d%d",&n,&m);
    num = m * 3 / 2;
    for(int i = 0; i < n; ++i)
        scanf("%d%d",&arr[i].k,&arr[i].s);
    sort(arr,arr+n,cmp);

    line = arr[num-1].s;
    printf("%d ",line);
    for(int i = 0; i < n; ++i)
        if(arr[i].s >= line) cnt++;
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; ++i)
        printf("%d %d\n",arr[i].k,arr[i].s);
    return 0;
}

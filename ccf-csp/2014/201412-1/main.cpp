#include <cstdio>
#include <climits>
#include <algorithm>

typedef struct {
    int id;
    int cnt = 1;
}Reader;

const int MAXN = 1005;

int records[MAXN];
int temp[MAXN];
int ids[MAXN];
Reader readers[MAXN];

using namespace std;

int main()
{
    int n, m = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", records+i);
        temp[i] = records[i];
    }

    temp[0] = INT_MAX;

    sort(temp+1, temp+1+n);

    for(int i = n; i >= 1; --i)
        if(temp[i] != temp[i-1]) readers[m++].id = temp[i];

    for(int i = 1; i < m; ++i)
        for(int j = 1; j <=n ; ++j)
            if(readers[i].id == records[j]) ids[j] = readers[i].cnt++;

    for(int i = 1; i <= n; ++i)
        if(i != n) printf("%d ", ids[i]);
        else printf("%d\n", ids[i]);

    return 0;
}

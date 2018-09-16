#include <cstdio>
#include <algorithm>

typedef struct{
    int num;
    int a;
    int v = 1;    // 1:right -1:left
}Ball;

const int MAXN = 105;

using namespace std;

Ball balls[MAXN];

bool cmp1(const Ball &a, const Ball &b)
{
    return a.a < b.a;    // 位置从小到大排序
}

bool cmp2(const Ball &a, const Ball &b)
{
    return a.num < b.num;    // 编号从小到大排序
}

int main()
{
    int n, L, t;
    scanf("%d%d%d", &n, &L,&t);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &balls[i].a);
        balls[i].num = i;
    }

    sort(balls+1, balls+1+n, cmp1);

    for(int i = 1; i <= t; ++i){
        for(int j = 1; j <= n; ++j)
            balls[j].a += balls[j].v;

        // 端点
        if(balls[n].a == L) balls[n].v = -balls[n].v;
        if(balls[1].a == 0) balls[1].v = -balls[1].v;

        for(int j = 1; j <= n-1; ++j){

            if(balls[j].a == balls[j+1].a){
                balls[j].v = -balls[j].v;
                balls[j+1].v = -balls[j+1].v;
            }
        }
    }

    sort(balls+1, balls+1+n, cmp2);

    for(int i = 1; i <= n-1; ++i){
        printf("%d ", balls[i].a);
    }
    printf("%d\n", balls[n].a);

    return 0;
}

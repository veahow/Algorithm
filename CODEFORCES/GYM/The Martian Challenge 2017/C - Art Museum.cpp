#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int a,b;
}Martian;

const int MAXN = 1E5 + 5;
int n,m[MAXN],ans;
Martian galaxies[MAXN];

bool cmp(Martian ga1,Martian ga2)
{
    if(ga1.b == ga2.b) return ga1.a < ga2.a;
    return ga1.b < ga2.b;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        m[i] = 1;
    for(int i = 0; i < n; ++i)
        scanf("%d%d",&galaxies[i].a,&galaxies[i].b);
    sort(galaxies,galaxies+n,cmp);

    for(int i = 0; i < n; ++i){
        bool isTrue = false;
        for(int j = i + 1; j < n; ++j)
            if(galaxies[i].b > galaxies[j].a) m[i]++;
        ans = max(ans,m[i]);
    }
    printf("%d\n",ans);
    return 0;
}


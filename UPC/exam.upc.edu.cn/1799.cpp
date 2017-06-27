#include <cstdio>

const int MAXN = 1000 + 5;
int n;
int num[MAXN] = {6,2,5,5,4,5,6,3,7,6};
int ans;

int main()
{
    scanf("%d",&n);
    n -= 4;
    for(int i = 10; i < 1000; ++i)
        num[i] = num[i/10] + num[i%10];
    for(int i = 0; i < 1000; ++i)
        for(int j = 0; j < 1000; ++j)
            if(i + j < 1000 && num[i] + num[j] + num[j+i] == n) ans++;
    printf("%d\n",ans);
    return 0;
}

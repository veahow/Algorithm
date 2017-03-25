#include <cstdio>
#include <cstring>

const int MAXN = 80 + 5;
int T;

int main()
{
    scanf("%d",&T);
    getchar();
    while(T--){
        char str[MAXN];
        int ans = 0,n = 0;
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0; i < len; ++i){
            if(str[i] == 'O') n++;
            if(str[i] == 'X') n = 0;
            ans += n;
        }
        printf("%d\n",ans);
    }
    return 0;
}

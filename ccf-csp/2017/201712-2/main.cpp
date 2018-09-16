#include <cstdio>
#include <cstring>

const int MAXN = 1005;
int flag[MAXN];

int main()
{
    int n, k, cnt, num = 0, i = 1;
    scanf("%d%d", &n, &k);
    memset(flag, 0, sizeof(int)*(n+1));
    cnt = n;

    while(cnt != 1){
        if(i > n) i = 1;
        if(!flag[i]) num++;
        else{
            i++;
            continue;
        }
        if(num % k == 0 || num % 10 == k){
            flag[i] = 1;
            cnt--;
        }
        i++;
    }

    for(int i = 1; i <= n; ++i){
        if(!flag[i]){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

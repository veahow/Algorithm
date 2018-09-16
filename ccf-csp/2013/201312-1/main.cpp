#include <cstdio>

const int MAXN = 10005;

using namespace std;

int num_cnt[MAXN];

int main()
{
    int n, s, max_cnt = 0, ans;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
        scanf("%d", &s);
        num_cnt[s]++;
    }

    for(int i = 1; i <= MAXN; ++i){
        if(num_cnt[i] > max_cnt){
            ans = i;
            max_cnt = num_cnt[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}

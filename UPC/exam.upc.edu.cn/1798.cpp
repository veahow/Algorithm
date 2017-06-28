#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 5;
char str[MAXN];
int word_count[MAXN];
int maxn = INT_MIN,minn = INT_MAX;
int ans;

bool Judge(int n)
{
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    scanf("%s",str);
    int l = strlen(str);
    for(int i = 0; i < l; ++i)
        word_count[str[i] - 'a']++;
    for(int i = 0; i < MAXN; ++i){
        if(word_count[i] == 0) continue;
        maxn = max(maxn,word_count[i]);
        minn = min(minn,word_count[i]);
    }
    ans = maxn - minn;
    if(Judge(ans)) printf("Lucky Word\n%d\n",ans);
    else printf("No Answer\n0\n");
    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 5;
int n,k,lens[MAXN],maxlen;
char str[MAXN];

int main()
{
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; ++i)
        lens[i] = 1;
    scanf("%s",str);

    for(int i = 1; i < n; ++i)
        if(str[i] == str[i-1]) lens[i] = lens[i-1] + 1;
    for(int i = 0; i < n; ++i)
        maxlen = max(maxlen,lens[i]);
    for(int i = 0; i < n; ++i)
        if(maxlen == lens[i]) k++;
    printf("%d\n",k);
    for(int i = 0; i < n; ++i)
        if(maxlen == lens[i]){
            for(int j = i; j >= 0; --j)
                if(str[i] == str[j]) printf("%c",str[j]);
            putchar('\n');
        }

    return 0;
}

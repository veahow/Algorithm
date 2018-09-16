#include <cstdio>

const int MAXN = 1005;

int main()
{
    int n, arr[MAXN], temp = 0, cnt = 1;

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
        scanf("%d", arr+i);

    temp = arr[1];

    for(int i = 2; i <= n; ++i)
        if(temp != arr[i]){
            temp = arr[i];
            cnt++;
        }

    printf("%d\n", cnt);

    return 0;
}

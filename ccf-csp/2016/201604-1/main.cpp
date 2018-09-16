#include <cstdio>

const int MAXN = 1005;

int main()
{
    int n, arr[MAXN], temp = 0, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", arr+i);

    for(int i = 2; i <= n-1; ++i){
        if(arr[i] > arr[i+1] && arr[i] > arr[i-1]) cnt++;
        if(arr[i] < arr[i+1] && arr[i] < arr[i-1]) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}

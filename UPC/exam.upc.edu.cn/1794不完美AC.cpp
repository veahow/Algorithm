#include <cstdio>

const int MAXN = 10000;
int n;
int start;
int arr[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i <= n; ++i)
        scanf("%d",&arr[i]);
    for(int i = 0; i < n; ++i)
        if(arr[i] != 0){
            start = i;
            break;
        }
    if(n == 1){
        if(arr[0] > 0){
            if(arr[0] == 1) printf("x");
            else printf("%dx",arr[0]);
        }
        if(arr[0] < 0){
            if(arr[0] == -1) printf("-x");
            else printf("%dx",arr[0]);
        }
        if(arr[1] > 0){
            if(arr[0] != 0) printf("+%d",arr[1]);
            else printf("%d",arr[1]);
        }
        if(arr[1] < 0) printf("%d",arr[1]);
        printf("\n");
        return 0;
    }

    if(arr[start] == 1) printf("x^%d",n-start);
    else if(arr[start] == -1) printf("-x^%d",n-start);
    else printf("%dx^%d",arr[start],n-start);
    for(int i = start + 1; i < n - 1; ++i){
        if(arr[i] > 0){
            if(arr[i] == 1) printf("+x^%d",n-i);
            else printf("+%dx^%d",arr[i],n-i);
        }
        if(arr[i] < 0){
            if(arr[i] == -1) printf("-x^%d",n-i);
            else printf("%dx^%d",arr[i],n-i);
        }
    }
    if(arr[n-1] > 0){
        if(arr[n-1] == 1) printf("+x");
        else printf("+%dx",arr[n-1]);
    }
    if(arr[n-1] < 0){
        if(arr[n-1] == -1) printf("-x");
        else printf("%dx",arr[n-1]);
    }
    if(arr[n] > 0) printf("+%d",arr[n]);
    if(arr[n] < 0) printf("%d",arr[n]);
    printf("\n");

    return 0;
}

#include <cstdio>
#include <cstring>

const int MAXN = 100 + 5;
int n;
int arr[MAXN];
bool isFound[MAXN];
int ans;

void Search(int num)
{
    for(int i = 0; i < n; ++i)
        if(arr[i] == num){
            isFound[i] = true;
            break;
        }
}

int main()
{
    memset(isFound,false,sizeof(isFound));
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%d",&arr[i]);

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int num = arr[i] + arr[j];
            Search(num);
        }
    }
    for(int i = 0; i < n; ++i)
        if(isFound[i] == true) ans++;

    printf("%d\n",ans);
    return 0;
}

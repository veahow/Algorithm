#include <cstdio>

const int MAXN = 505;

using namespace std;

int arr[MAXN];
int flag[MAXN];

int main()
{
    int N, cnt = 0;
    scanf("%d", &N);
    arr[0] = 0;
    flag[0] = 0;

    for(int i = 1; i <= N; ++i){
        scanf("%d", arr+i);
        flag[i] = 1;
    }

    for(int i = N; i >= 1; --i){
        for(int j = i-1; j >= 1; --j)
            if(flag[j]){
                if(arr[i] + arr[j] == 0){
                    flag[j] = 0;
                    flag[i] = 0;
                    cnt++;
                    break;
                }
            }else continue;
    }

    printf("%d\n", cnt);

    return 0;
}

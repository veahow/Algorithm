#include <cstdio>
#include <algorithm>

typedef struct{
    int key;
    int time;    // 时间统一
    int borrow;    // 0:借 1:还
}Teacher;

const int MAXN = 1005;
int keys[MAXN];    // 0:没被取 1:被取
Teacher arr[2*MAXN];    // 假设每个老师都有一个分身 开始借和结束还的都是同一个钥匙

using namespace std;

int cmp(const Teacher &a, const Teacher &b)
{
    if(a.time == b.time){
        if(a.borrow == b.borrow) return a.key < b.key;
        return a.borrow > b.borrow;
    }
    return a.time < b.time;
}

int main()
{
    int N, K, w, s, c;
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; ++i)
        keys[i] = i;

    for(int i = 1; i <= 2*K - 1; i += 2){
        scanf("%d%d%d", &w, &s, &c);

        arr[i].key = w;    // 借的钥匙
        arr[i+1].key = w;    // 还的钥匙
        arr[i].time = s;    // 借的时刻
        arr[i+1].time = s + c;    // 还的时刻
        arr[i].borrow = 0;    // 借
        arr[i+1].borrow = 1;    // 还
    }

    sort(arr+1, arr+1+2*K, cmp);

    for(int i = 1; i <= 2*K; ++i){
        if(arr[i].borrow){
            for(int j = 1; j <= N; ++j){
                if(!keys[j]){
                    keys[j] = arr[i].key;
                    break;
                }
            }
        }else{
            for(int j = 1; j <= N; ++j){
                if(keys[j] == arr[i].key){
                    keys[j] = 0;
                    break;
                }
            }
        }

    }


    for(int i = 1; i <= N-1; ++i)
        printf("%d ", keys[i]);
    printf("%d\n", keys[N]);

    return 0;
}

#include <cstdio>
#include <algorithm>

typedef struct{
    int key;
    int time;    // ʱ��ͳһ
    int borrow;    // 0:�� 1:��
}Teacher;

const int MAXN = 1005;
int keys[MAXN];    // 0:û��ȡ 1:��ȡ
Teacher arr[2*MAXN];    // ����ÿ����ʦ����һ������ ��ʼ��ͽ������Ķ���ͬһ��Կ��

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

        arr[i].key = w;    // ���Կ��
        arr[i+1].key = w;    // ����Կ��
        arr[i].time = s;    // ���ʱ��
        arr[i+1].time = s + c;    // ����ʱ��
        arr[i].borrow = 0;    // ��
        arr[i+1].borrow = 1;    // ��
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

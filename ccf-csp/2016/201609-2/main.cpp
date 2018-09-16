#include <cstdio>

typedef struct{
    int num[10];
    int seats;
}Seat;

const int MAXN = 25;
Seat arr[MAXN];

void Arrange(int p)
{
    int row, cnt = 0, flag = 0, temp = 0;
    for(int i = 1; i <= 20; ++i){
        if(arr[i].seats >= p){
            row = i;
            flag = 1;    // ���԰�����һ�ŵ���λ
            break;
        }
    }

    if(flag){
        arr[row].seats -= p;
        for(int i = 1; i <= 5; ++i){
            if(arr[row].num[i] == 0){
                arr[row].num[i] = 1;    // ռλ
                printf("%d", (row-1)*5+i);

                cnt++;
                if(cnt != p) printf(" ");
                else{
                    printf("\n");
                    break;
                }
            }
        }
    }else{
        for(int i = 1; i <= 20; ++i){
            for(int j = 1; j <= 5; ++j){
                if(arr[i].num[j] == 0){
                    arr[i].num[j] = 1;    // ռλ
                    arr[i].seats--;
                    printf("%d", (i-1)*5+j);

                    cnt++;
                    if(cnt != p) printf(" ");
                    else{
                        printf("\n");
                        temp = 1;
                        break;
                    }
                }
            }
            if(temp) break;
        }
    }
}

int main()
{
    int n, p;
    scanf("%d", &n);
    for(int i = 1; i <= 20; ++i)
        arr[i].seats = 5;    // ÿһ��5����λ

    for(int i = 1; i <= n; ++i){
        scanf("%d", &p);
        Arrange(p);
    }

    return 0;
}

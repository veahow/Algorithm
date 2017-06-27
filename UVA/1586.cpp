#include <cstdio>
#include <cstring>

const int MAXN = 80 + 5;
int T;
char str[MAXN];
double value[4] = {12.01,1.008,16,14.01};

int main()
{
    scanf("%d",&T);
    getchar();
    while(T--){
        double ans = 0;
        int num1,num2;
        memset(str,0,sizeof(str));
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0; i < len; ++i){
            if(str[i] < '0' || str[i] > '9'){
                double v;
                int num;
                if(str[i] == 'C') v = value[0];
                if(str[i] == 'H') v = value[1];
                if(str[i] == 'O') v = value[2];
                if(str[i] == 'N') v = value[3];

                if(str[i+1] >= '1' && str[i+1] <= '9'){
                    if(str[i+2] >= '0' && str[i+2] <= '9'){
                        int num1 = str[i+1] - '0',num2 = str[i+2] - '0';
                        num = num1*10+num2;
                    }else num = str[i+1] - '0';
                }else num = 1;
                ans += v*num;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

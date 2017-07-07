#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int id,s,w;
}Person;

const int MAXN = 100000 * 2 + 5;
Person win[MAXN],lose[MAXN],ans[MAXN];
int N,R,Q;

bool cmp(Person a,Person b)
{
    if(a.s == b.s) return a.id < b.id;
    return a.s > b.s;
}

void MergeSort()
{
    int win_var = 0,lose_var = 0;
    for(int i = 0; i < N; i += 2){
        if(ans[i].w > ans[i+1].w){
            ans[i].s++;
            win[win_var++] = ans[i];
            lose[lose_var++] = ans[i+1];
        }else{
            ans[i+1].s++;
            win[win_var++] = ans[i+1];
            lose[lose_var++] = ans[i];
        }
    }

    int i = 0,j = 0,k = 0;
    while(i < win_var && j < lose_var){
        if(cmp(win[i],lose[j])) ans[k++] = win[i++];
        else ans[k++] = lose[j++];
    }
    while(i < win_var) ans[k++] = win[i++];
    while(j < lose_var) ans[k++] = lose[j++];
}

int main()
{
    scanf("%d%d%d",&N,&R,&Q);
    N *= 2;
    for(int i = 0; i < N; ++i){
        scanf("%d",&ans[i].s);
        ans[i].id = i+1;
    }
    for(int i = 0; i < N; ++i)
        scanf("%d",&ans[i].w);
    sort(ans,ans+N,cmp);

    while(R--) MergeSort();
    printf("%d\n",ans[Q-1].id);
    return 0;
}

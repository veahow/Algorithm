#include <cstdio>

using namespace std;

int a;
int arr[100];
int n;
int des;

int BiSearch(int l,int r)
{
    int mid;
    while(l<=r){
        if(arr[l]==des) return l;
        if(arr[r]==des) return r;

        mid=(l+r)/2;
        if(arr[mid]>des) r=mid-1;
        if(arr[mid]<des) l=mid+1;
        if(arr[mid]==des) return mid;
    }

    if(l>r){
        if(arr[r]>des) return r;
        if(arr[r]<des) return r+1;
    }
}

int main()
{
    while(scanf("%d",&a)!=EOF){
        if(a==0) break;
        arr[n]=a;
        n++;
    }
    scanf("%d",&des);

    if(n==1){
        if(des<=arr[0]) printf("0\n");
        else printf("1\n");

        return 0;
    }

    if(n==2){
        if(arr[0]<des && des<=arr[1]) printf("1\n");
        if(arr[0]>=des) printf("0\n");
        if(arr[1]<des) printf("2\n");
        return 0;
    }

    printf("%d\n",BiSearch(0,n-1));

    return 0;
}

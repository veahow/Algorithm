#include <cstdio>

void Print(char isbn[])
{
    for(int i = 1; i <= 9; i++){
        if(i == 2 || i == 5) printf("-");
        printf("%c", isbn[i]);
    }

}

int main()
{
    int i = 1, sum = 0, num;
    char isbn[15], ch;
    while((ch=getchar()) != '\n'){
        if(ch == '-') continue;
        isbn[i++] = ch;
    }
    for(int i = 1; i <= 9; ++i)
        sum += i*((int)(isbn[i]) - 48);
    num = sum % 11;
    if(num == 10){
        if('X' == isbn[10]) printf("Right\n");
        else{
            Print(isbn);
            printf("-X\n");
        }
    }else{
        if(num + 48 == isbn[10]) printf("Right\n");
        else{
            Print(isbn);
            printf("-%c\n", num + 48);
        }
    }

    return 0;
}

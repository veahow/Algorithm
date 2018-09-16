#include <cstdio>
#include <cmath>
#include <cstdlib>

typedef struct Student{
    int data;
    struct Student *prior;
    struct Student *next;
}Student, *StuPtr;


StuPtr Init_List(int n)
{
    StuPtr head, tail, p, q;
    head = (StuPtr)malloc(sizeof(Student));
    tail = (StuPtr)malloc(sizeof(Student));
    head->prior = NULL;
    head->data = 0;    // 表示为头部节点
    head->next = NULL;

    p = (StuPtr)malloc(sizeof(Student));
    head->next = p;
    p->prior = head;
    for(int i = 1; i <= n; ++i){
        p->data = i;

        q = (StuPtr)malloc(sizeof(Student));
        p->next = q;
        q->prior = p;
        p = q;
    }
    tail = p;
    tail->next = NULL;
    tail->data = -1;

    return head;
}

StuPtr Search(StuPtr L, int num)
{
    StuPtr p = L->next;
    while(p->data != -1){
        if(p->data == num) return p;
        p = p->next;
    }
    // 一般来说是找得到的 这里不作未找到处理
}

void NextMove(StuPtr p, StuPtr q)
{
    // 将准备移动的节点断链
    StuPtr t;
    t = p->next;
    t->prior = p->prior;
    p->prior->next = t;
    p->next = NULL;
    p->prior = NULL;

    // 准备移动的节点开始移动到相应位置
    t = q->next;
    q->next = p;
    p->prior = q;
    p->next = t;
    t->prior = p;
}

void PriorMove(StuPtr p, StuPtr q)
{
    // 将准备移动的节点断链
    StuPtr t;
    t = p->next;
    t->prior = p->prior;
    p->prior->next = t;
    p->next = NULL;
    p->prior = NULL;

    // 准备移动的节点开始移动到相应位置
    t = q->prior;
    q->prior = p;
    p->next = q;
    p->prior = t;
    t->next = p;
}

void Handle(StuPtr L, int num, int dist)
{
    StuPtr p, q;
    int n = abs(dist);
    p = Search(L, num);
    q = p;
    if(dist == 0) return;
    if(dist > 0){
        while(n--) q = q->next;
        NextMove(p, q);
    }
    if(dist < 0){
        while(n--) q = q->prior;
        PriorMove(p, q);
    }
}

void Output(StuPtr L, int n)
{
    StuPtr p = L->next;
    for(int i = 1; i <= n-1; ++i){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

int main()
{
    int n, m, num, dist;
    StuPtr L;
    scanf("%d%d", &n, &m);
    L = Init_List(n);

    for(int i = 1; i <= m; ++i){
        scanf("%d%d", &num, &dist);
        Handle(L, num, dist);
    }

    Output(L, n);

    return 0;
}

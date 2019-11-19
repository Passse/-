#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node* Next;
};
typedef struct Node* N;

struct QNode
{
    N Front,Rear;
    int maxsize;
};
typedef struct QNode* QN;

QN CreateQ(int maxsize)
{
    QN Q=(QN)malloc(sizeof(struct QNode));
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->Next=NULL;
    Q->Front=Q->Rear=p;
    return Q;
}

int IsEmpty(QN Q)
{
    return (Q->Front==NULL);
}

int AddQ(QN Q,int x)
{
    N n=(N)malloc(sizeof(struct Node));
    n->Data=x;
    n->Next=NULL;
    Q->Rear->Next=n;
    Q->Rear=n;
    return 1;
}

int DeletQ(QN Q)
{
    N FrontCell;
    int FrontElem;
    if(IsEmpty(Q))
    {
        printf("队列空");
        return 0;
    }
    else{
        FrontCell=Q->Front;
        if(Q->Front==Q->Rear)
            Q->Front=Q->Rear=NULL;
        else
            Q->Front=Q->Front->Next;
        FrontElem=FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }
}

 int main()
{
    int maxsize=5;
    int x;
    int i=0;
    QN Q=CreateQ(maxsize);
    while(i<5)
    {
        if(IsEmpty(Q))
            break;
        scanf("%d",&x);
        AddQ(Q,x);
        printf("%d",DeletQ(Q));
    }
    return 0;
}

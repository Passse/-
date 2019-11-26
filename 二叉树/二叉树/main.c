#include<stdio.h>
#include<stdlib.h>

typedef struct TNode* BinTree;
struct TNode
{
    int Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreateBinTree()
{
    int k;
    scanf("%d",&k);
    if(k==0)
    {
        return NULL;
    }
    BinTree T=(BinTree)malloc(sizeof(BinTree));
    T->Data=k;
    T->Left=CreateBinTree();
    T->Right=CreateBinTree();
    return T;
}

void operate()
{
    printf("1.先序遍历二叉树\n");
    printf("2.中序遍历二叉树\n");
    printf("3.后续遍历二叉树\n");
    printf("4.层序遍历二叉树\n");
    printf("5.打印叶子结点\n");
    printf("6.计算树高\n");
    printf("请选择您需要的操作:");
}

void xianxu(BinTree T)
{
    if(T)
    {
        printf("%d ",T->Data);
        xianxu(T->Left);
        xianxu(T->Right);
    }
}

void zhongxu(BinTree T)
{
    if(T)
    {
        zhongxu(T->Left);
        printf("%d ",T->Data);
        zhongxu(T->Right);
    }
}

void houxu(BinTree T)
{
    if(T)
    {
        houxu(T->Left);
        houxu(T->Right);
        printf("%d ",T->Data);
    }
}

void cengxu(BinTree T)
{
    if(T)
    {
        BinTree a[100];
        int rear=0;
        int front=0;
        a[++rear]=T;
        while(rear!=front)
        {
            BinTree m=a[++front];
            printf("%d ",m->Data);
            if(m->Left!=NULL)
                a[++rear]=m->Left;
            if(m->Right!=NULL)
                a[++rear]=m->Right;
        }
    }
}

void yezi(BinTree BT)
{
    if(BT)
    {
        if(!BT->Left && !BT->Right)
        {
            printf("%d ",BT->Data);
        }
        yezi(BT->Left);
        yezi(BT->Right);
    }
}

int Height(BinTree BT)
{
    int HL,HR,MaxH;
    if(BT)
    {
        HL=Height(BT->Left);
        HR=Height(BT->Right);
        MaxH=HL>HR?HL:HR;
        return(MaxH+1);
    }
    else
        return 0;
}
int main()
{
    printf("请输入二叉树:\n");
    BinTree T=CreateBinTree();
    operate();
    while(1)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            xianxu(T);
            printf("\n");
        }
        else if(op==2)
        {
            zhongxu(T);
            printf("\n");
        }
        else if(op==3)
        {
            houxu(T);
            printf("\n");
        }
        else if(op==4)
        {
            cengxu(T);
            printf("\n");
        }
        else if(op==5)
        {
            yezi(T);
            printf("\n");
        }
        else if(op==6)
        {
            printf("%d",Height(T));
            printf("\n");
        }
    }
    return 0;
}

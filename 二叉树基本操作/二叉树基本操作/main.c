#include<stdio.h>
#include<stdlib.h>

typedef struct TNode* BinTree;
struct TNode
{
    char Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreateBinTree()
{
    char k;
    scanf("%c",&k);
    if(k=='#')
    {
        return NULL;
    }
    BinTree T=(BinTree)malloc(sizeof(BinTree));
    T->Data=k;
    T->Left=CreateBinTree();
    T->Right=CreateBinTree();
    return T;
}

void xianxu(BinTree T)
{
    if(T){
        printf("%2c",T->Data);
        xianxu(T->Left);
        xianxu(T->Right);
    }
}

void houxu(BinTree T)
{
    if(T)
    {
        houxu(T->Left);
        houxu(T->Right);
        printf("%2c",T->Data);
    }
}

void zhongxu(BinTree T)
{
    if(T)
    {
        zhongxu(T->Left);
        printf("%2c",T->Data);
        zhongxu(T->Right);
    }
}

void yezi(BinTree T)
{
    if(T)
    {
        if(!T->Left&&!T->Right)
        {
            printf("%2c",T->Data);
        }
        yezi(T->Left);
        yezi(T->Right);
    }
}

int Hight(BinTree T)
{
    int HL,HR,MaxH;
    if(T)
    {
        HL=Hight(T->Left);
        HR=Hight(T->Right);
        MaxH=HL>HR?HL :HR;
        return (MaxH+1);
    }
    else
        return 0;
}
int main()
{
    BinTree T=CreateBinTree();
    xianxu(T);
    houxu(T);
    zhongxu(T);
    printf("\n");
    yezi(T);
    printf("\n");
    printf("%d",Hight(T));
    printf("\n");
    return 0;
}

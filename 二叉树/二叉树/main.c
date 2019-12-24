#include<stdio.h>
#include<stdlib.h>
#define MAXDATA 1000

typedef struct TNode* BinTree;
struct TNode
{
    int Data;
    BinTree Left;
    BinTree Right;
};

typedef struct HNode* Heap;
struct HNode
{
    int *Data;
    int Size;
    int Capacity;
};

Heap CreateHeap(int MaxSize)
{
    Heap H=(Heap)malloc(sizeof(struct HNode));
    H->Data=(int*)malloc((MaxSize+1)*sizeof(int));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}

int IsFull(Heap H)
{
    if(H->Size==H->Capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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
    printf("7.打印树形\n");
    printf("8.判断该树是否为搜索二叉树\n");
    printf("请选择您需要的操作:\n");
}

void opBST()
{
    printf("1.输出二叉搜索树的最大值\n");
    printf("2.输出二叉搜索树的最小值\n");
    printf("3.查找二叉搜索树中的值\n");
    printf("4.向二叉搜索树中插入值\n");
    printf("5.将二叉搜索树中的值删除\n");
    printf("6.打印二叉搜索树\n");
    printf("7.两节点之间的路径\n");
    printf("8.退出二叉搜索树的操作\n");
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

void PrintTree(BinTree BT,int N)
{
    if(BT)
    {
        PrintTree(BT->Right,N+1);
        
        for(int i=0;i<N;i++)
        {
            printf("   ");
        }
        
        printf("%d\n",BT->Data);
        
        PrintTree(BT->Left,N+1);
    }
}

int p[1000];
int rear=0;
int IsBST(BinTree BST)
{
    if(BST)
    {
        IsBST(BST->Left);
        p[++rear]=BST->Data;
        IsBST(BST->Right);
        for(int i=0;i<rear;i++)
        {
            for(int j=i+1;j<rear;j++)
            {
                if(p[i]>p[j])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

BinTree FindMin(BinTree BST)
{
    if(!BST) return 0;
    else if(!BST->Left) return BST;
    else return FindMin(BST->Left);
}

BinTree FindMax(BinTree BST)
{
    if(!BST)    return 0;
    else if(!BST->Right)    return BST;
    else return FindMax(BST->Right);
}

int m1=0;
BinTree Find(BinTree BST,int C)
{
    while(BST)
    {
        if(C<BST->Data)
        {
            BST=BST->Left;
        }
        else if(C>BST->Data)
        {
            BST=BST->Right;
        }
        else
        {
            m1=1;
            break;
        }
    }
    return BST;
}

int i;
BinTree Insert(BinTree BST,int C)
{
    if(!BST)
    {
        BST=(BinTree)malloc(sizeof(BinTree));
        BST->Data=C;
        BST->Left=BST->Right=NULL;
    }
    else
    {
        if(C<BST->Data)
        {
            BST->Left=Insert(BST->Left,C);
        }
        else if(C>BST->Data)
        {
            BST->Right=Insert(BST->Right,C);
        }
        else
        {
            i=1;
        }
    }
    return BST;
}

BinTree Delete(BinTree BST,int C)
{
    BinTree Tmp;
    if(!BST)
    {
        printf("要删除的元素未找到\n");
    }
    else
    {
        if(C<BST->Data)
            BST->Left=Delete(BST->Left,C);
        else if(C>BST->Data)
            BST->Right=Delete(BST->Right,C);
        else
        {
            if(BST->Left && BST->Right)
            {
                Tmp=FindMin(BST->Right);
                BST->Data=Tmp->Data;
            }
            else
            {
                Tmp=BST;
                if(!BST->Left)
                    BST=BST->Right;
                else
                    BST=BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}

void Road(BinTree BST,int a,int b)
{
    BinTree p1=Find(BST,a);
    BinTree p2=Find(BST,b);
    while(p1!=NULL)
    {
        if(p1->Data>p2->Data)
        {
            printf("%d ",p1->Data);
            p1=p1->Right;
        }
        else if(p1->Data<p2->Data)
        {
            printf("%d ",p1->Data);
            p1=p1->Left;
        }
        else
        {
            printf("%d ",p1->Data);
            break;
        }
    }
}

void view(BinTree T)
{
    int opB;
    while(1)
    {
        scanf("%d",&opB);
        if(opB==1)
        {
            BinTree p=FindMin(T);
            printf("最小值为:%d\n",p->Data);
        }
        if(opB==2)
        {
            BinTree p=FindMax(T);
            printf("最大值为:%d\n",p->Data);
        }
        if(opB==3)
        {
            int c;
            printf("请输入想要查找的值:");
            scanf("%d",&c);
            Find(T,c);
            if(m1==1)
            {
                printf("二叉树中存在该值\n");
                m1=0;
            }
            else
            {
                printf("二叉树中没有该值\n");
            }
        }
        if(opB==4)
        {
            int C;
            printf("输入您想插入的值:");
            scanf("%d",&C);
            Insert(T,C);
            if(i==1)
            {
                printf("该二叉搜索树中已存在该值\n");
                i=0;
            }
            if(i==0)
            {
                printf("插入成功\n");
                PrintTree(T,1);
            }
        }
        if(opB==5)
        {
            int C;
            printf("请输入您想删除的值:");
            scanf("%d",&C);
            Delete(T,C);
            printf("删除成功\n");
            PrintTree(T,1);
        }
        if(opB==6)
        {
            PrintTree(T,1);
            printf("\n");
        }
        if(opB==7)
        {
            int a,b;
            printf("输入两个节点的值:\n");
            scanf("%d %d",&a,&b);
            printf("两顶点之间的距离为:");
            Road(T,a,b);
            printf("\n");
        }
        if(opB==8)
        {
            operate();
            break;
        }
    }
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
            printf("先序遍历二叉树:");
            xianxu(T);
            printf("\n");
        }
        else if(op==2)
        {
            printf("中序遍历二叉树:");
            zhongxu(T);
            printf("\n");
        }
        else if(op==3)
        {
            printf("后序遍历二叉树:");
            houxu(T);
            printf("\n");
        }
        else if(op==4)
        {
            printf("层序遍历二叉树:");
            cengxu(T);
            printf("\n");
        }
        else if(op==5)
        {
            printf("打印叶子结点:");
            yezi(T);
            printf("\n");
        }
        else if(op==6)
        {
            printf("计算树高:");
            printf("%d",Height(T));
            printf("\n");
        }
        else if(op==7)
        {
            printf("打印树形:\n");
            PrintTree(T,1);
            printf("\n\n");
        }
        else if(op==8)
        {
            if(IsBST(T))
            {
                printf("该树是二叉搜索树\n");
                printf("请选择您需要的操作:\n");
                opBST();
                view(T);
            }
            else
            {
                printf("该树不是二叉搜索树\n");
            }
        }
    }
    return 0;
}
//30 33 10 0 0 25 0 0 35 34 0 0 0
//30 20 10 0 0 25 0 0 35 34 0 0 0
//30 15 0 0 41 33 0 0 50 0 0

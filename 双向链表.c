#include<stdlib.h>

typedef struct{
    int data;
}ElemType;


typedef struct Lnode{
    ElemType Elem;
    struct Lnode *next,*prior;
}Lnode,*LinkList;




//获取双向链表第i个结点的地址
LinkList GetP_Double_LinkList(LinkList list,int i)
{
    LinkList p;
    int j = 1;
    p = list->next;
    while(p && j<i)
    {
        p = p->next;
        j++
    }
    if(!p || j>i) return NULL;
    return p;
}


//双向链表：有两个指针域，一个指向前驱，一个指向后继

//双向链表的插入
//第i个结点前插入
int Insert_Double_LinkList(LinkList list,int i,ElemType e)
{
    LinkList p,q;
    if(!(p = GetP_Double_LinkList(list,i)))   return -1;   //获取第i个结点的地址p
    q = (LinkList)malloc(sizeof(Lnode));
    q->Elem = e;
    q->prior = p->prior;
    p->prior->next = q;
    q->next = p;
    p->prior = q;
    return 0;
}


//双向链表:删除第i个结点以及数据
int Delete_Double_LinkList(LinkList list,int i)
{
    LinkList p;
    if(!(p = GetP_Double_LinkList(list,i))) return -1;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 0;
}



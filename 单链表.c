
/*以下链表所有操作都基于带有头指针的链表*/
typedef struct{
    int data;
}ElemType;


typedef struct Lnode{
    ElemType Elem;
    struct Lnode *next;
}Lnode,*LinkList;

//初始化一个单链表
int Init_LinkList(LinkList list)
{
    list = (LinkList)malloc(sizeof(LinkList));
    if(list == NULL)  //未分配到内存则抛出异常
        return -1;
    list->next = NULL;
    return 0;
}

//判断一个单链表是否为空表
int LinkList_IsEmpty(LinkList list)
{
    if(list == NULL)  
        return -1; //空表返回-1
    return 0;
}

//销毁一个单链表
void Destroy_LinkList(LinkList list)
{
    LinkList p;
    while(list)
    {
        p = list;   //先保留头结点的地址
        list = list->next;   //让头结点指向自己的指针域(也就是下一个结点的地址)
        free(list);   //释放下一个结点的地址
    }
}


//清空链表，成为空链表(保留头指针与头结点)
void Clear_LinkList(LinkList list)
{
    LinkList p,q;
    p = list->next;   //先让p指向首元结点的地址
    while(p)
    {
        q = p->next; //让q指向p的指针域
        free(p);   //这时候p可以放心释放，因为q已经有了下个结点的地址可以继续操作
        p = q;   //再将p指向q，然后进行循环释放下一个结点
    }
    list->next = NULL;   //所有结点释放完后将头结点的指针域置空，即可成为空链表
}


//求链表的表长(链表的元素个数)
int Lenth_LinkList(LinkList list)
{
    LinkList p;
    int i = 0;
    p = list->next;  //先拿到首元结点的地址
    while(p)  //循环到尾结点则跳出循环
    {
        i++;
        p = p->next;  //p指向下一个结点的地址
    }
    return i;
}


//获取链表中第i个元素的数据
int GetElem_LinkList(LinkList list,int i,ElemType e)
{
    LinkList p;
    int j = 1;
    p = list->next;    //拿到头结点的地址
    while(p && j<i)   //p为空或者j<i(也就是i不在链表范围内)，则跳出循环
    {
        p = p->next;  //指向下个结点
        j++;   //计数+1
    }
    if(!p || j<i)  return -1; //如果p是空的或者i是0、负数则地i个元素不存在
    e = list->Elem;
    return 0;
}

//单链表的按值查找1:返回位置
int Seek_LinkList(LinkList list,ElemType e)
{
    LinkList p;
    int i = 1;
    p = list->next;
    while(p && (p->Elem != e)){  //p为空或者要找的数据找到了
        p = p->next;
        i++;
    }
    if(p) 
        return i;   //返回位置
    return 0;
}

//单链表的按值查找2:返回地址
Lnode *Seek_LinkList(LinkList list,ElemType e)
{
    LinkList p;
    p = list->next;
    while(p && (p->Elem != e)){
        p = p->next;
    }
    return p;
}

//在第i个结点前插入值为e的新结点
void Insert_LinkList(LinkList list,int i,ElemType e)
{
    LinkList p,q;
    p = list->next;
    int j = 0;   //j=0说明i不能等于0也就是不算头指针，头结点是第一个元素
    while(p && j<(i-1)){  //找第i个元素的前一个元素
        p = p->next;
        j++;
    }
    if(!p || j>i-1)  return -1;    //i大于表长或小于1，插入位置非法
    q = (LinkList)malloc(sizeof(Lnode));  //分配一块新的内存给新的结点
    q->Elem = e;//新结点的数据初始化为e
    q->next = p->next;    //将q的指针域指向第i个结点(也就是第i-1结点的指针域)
    p->next = q;   //将第i-1个结点的指针域指向新结点
}

//删除第i个结点
void Delete_LinkList(LinkList list,int i)
{
    LinkList p,q;
    p = list->next;
    int j = 0;
    while(p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i -1) return -1;
    q = p->next;  //临时保存要删除结点的地址
    p->next = p->next->next;   //要删除的结点的前继结点的指针域指向要删除结点的后继结点，也可以改成p->next = q->next
    free(q);
}


/*建立单链表*/
/*1、头插法 2、中间任意位置插入 3、尾插法*/

//头插法  往链表头插入指定个数的结点
void Create_LinkList_H(LinkList list,int n)
{
    LinkList p;
    list = (LinkList)malloc(sizeof(Lnode));
    list->next = NULL;   //创建一个空表
    for(int i = n;i > 0;i--){
        p = (LinkList)malloc(sizeof(Lnode));   //为新结点分配内存
        scanf("%d",&(p->Elem));    //要插入的数据
        p->next = list->next;   //新结点的指针域指向头结点地址
        list->next = p;   //头指针指向新结点的地址
    }
}

//尾插法
void Create_LinkList_Back(LinkList list,int n)
{
    LinkList p,r = list;
    list = (LinkList)malloc(sizeof(Lnode));
    list->next = NULL;   //创建一个空表
    for(int i = n;i > 0;i--)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        scanf("%d\n",&(p->Elem));
        r->next = p;   //头结点指向新结点的地址
        p->next = NULL;   //新结点的指针域指向空
        r = p;    //r为尾指针，作为中间变量使用完后需要指向最后一个结点，这样才能循环多次插入
    }
}








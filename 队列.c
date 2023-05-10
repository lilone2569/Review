#define ERROR -1
#define OK  0
#define MAXQSIZE 100



/******************************顺序队列******************************/
/*******************************************************************/

typedef struct {
  int *base;   //初始化的动态分配的存储空间
  int *front;  //头指针
  int *rear;   //尾指针
}SqQueue;

//初始化一个队列
int InitQueue(SqQueue &Q){
    Q.base = (int *)malloc(sizeof(int) * MAXQSIZE);
    if(!Q.base) return ERROR;   //申请内存失败
    Q.front = Q.rear = NULL;
    return OK;
}

//求队列的长度
int QueueLenth(SqQueue Q){
    return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}


//循环队列入队
int QueueInsert(SqQueue Q,int data){
    if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; //是否队满
    Q.base[Q.rear] = data;  //data:要入队的数据
    Q.rear++;
    if()
    return OK;
}

//循环队列出队
int QueueDelete(SqQueue Q,int &data){
    int data;
    if(Q.rear == Q.front) return ERROR;  //是否队空
    data = Q.base[Q.front];  //保存出队的元素
    Q.front = (Q.front + 1) % MAXQSIZE;   //满足循环队列的条件
    return OK;
}



/*************************链式队列*******************/
/***************************************************/
//若无法估计所用队列的长度则采用链队列
typedef struct Qnode{
    int data;
    struct Qnode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;  //队头指针
    QueuePtr rear;  //队尾指针
}LinkQueue;


//初始化一个链队
int InitQueue(LinkQueue &Q){
    Q.front = Q.rear  = (LinkQueue)malloc(sizeof(QNode));
    Q.front->next = Q.rear->next = NULL;
    if((Q.front | Q.rear) == NULL) return ERROR;
    return OK;
}

//销毁链队
void DestroyQueue(LinkQueue &Q){
    while(Q.front){   
        Q.rear = Q.front->next;   //rear指针没用可以直接拿来用
        free(Q.front);
        Q.front = Q.rear;
    }
}



//将元素e入队
int QueueInsert(LinkQueue &Q,int e){
    QueuePtr *p = (QueuePtr *)malloc(sizeof(QNode));
    if(!p) return ERROR;
    p->data = e;
    Q.rear->next = p;
    Q.rear = p;
    p->next = NULL;
    return OK;
}

//链队出队
int QueueDelete(LinkQueue &Q,int &e){
    QueuePtr p;
    if(Q.front == Q.rear) return ERROR;
    p = Q.front->next;
    e = p->data;
    free(p);
    if(Q.rear == p) Q.rear = Q.front;
    return OK;
} 








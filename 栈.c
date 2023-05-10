
/*****************************顺序栈*****************************/
#define MAXSIZE 100

typedef int SElem_Type;


typedef struct{
    SElem_Type *base;
    SElem_Type *top;
    int stacksize;
}Seq_Stack;



//初始化栈
int Init_stack(Seq_Stack *S)
{
    S->base = (SElem_Type *)malloc(MAXSIZE*sizeof(SElem_Type)));
    if(!S->base) return -1;
    S.top = S.base;
    S->stacksize = MAXSIZE;
    return 0;
}


//销毁栈
void Destroy_Stack(Seq_Stack *S)
{
    if(S->base)
    {
        free(S->base);
        S->stacksize = 0;
        S->base = S->top = NULL;
    }
}

//清空栈
int Clear_Stack(Seq_Stack *S)
{
    if(S->base)
    {
        S->top = S->base;
        return 0;
    }
    return -1;   //栈底为空则返回错误
}


//判断是否为空栈
//为空则返回0，否则返回-1
int StackEmpty(Seq_Stack *S)
{
    if(S->base == S->top)
        return 0;
    return -1;
}




//求栈的长度
int StackLength(Seq_Stack *S)
{
    int len = (S->top - S->base);
    return len;
}



//入栈
int Push(Seq_Stack *S,SElem_Type e)
{
    if(S->top - S->base == S->stacksize) return -1;
    *S->top++ = e;
    return 0;
}


//出栈
int Pop(Seq_Stack *S,SElem_Type e)
{
    if(S->base == S->top) return -1;
    e = *(--S->top);
    return 0;
}



 







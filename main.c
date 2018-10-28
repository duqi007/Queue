#include <stdio.h>
#include <stdlib.h>

#define OK    1
#define ERROR 0

typedef char ElemType;
typedef int  Status;

typedef struct QNode{
    ElemType data;
    struct QNode * next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front;         //队头指针
    QueuePtr rear;          //队尾指针
}LinkQueue;

void visit(ElemType e);
//初始化队列
Status InitQueue(LinkQueue *Q){

    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next = NULL;
    printf("队列初始化成功！\n");
    return OK;
}
//进队
Status EnQueue(LinkQueue *Q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        return ERROR;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}
//显示队列元素
Status QueueTraverse(LinkQueue Q){
    QueuePtr p;
    p = Q.front;
    if(Q.front == Q.rear)return ERROR;
    while(p!=Q.rear){
        p = p->next;
        visit(p->data);
    }
    printf("\n");
    return OK;
}
//删除队头
Status DeQueue(LinkQueue *Q, ElemType *e){

    QueuePtr p;

    if(Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
        Q->rear = Q->front;
    free(p);
    printf("删除队头成功！\n");
    return OK;
}
//销毁队列
Status DestoryQueue(LinkQueue *Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }

    printf("销毁队列成功！\n");
    return OK;
}
//判断是否为空队列
 Status QueueEmpty(LinkQueue *Q){
    if(Q->front == Q->rear){
        printf("队列为空\n");
        return ERROR;
    }
    printf("队列不为空\n");
    return OK;
}
//求队列长度
int QueueLength(LinkQueue Q){
    if(QueueEmpty(&Q) == 0){
        return 0;
    }
    else{
        QueuePtr p;
        int i=0;
        p = Q.front->next;
        while(p){
            i++;
            p = p->next;
        }
        return i;
    }
}

//获取队头
Status GetHead(LinkQueue Q, ElemType *e){
    if(QueueEmpty(&Q) == 0 ){
        return ERROR;
    }
    else{
        *e = Q.front->next->data;
        return OK;
    }
}

//清空队列，记得和销毁队列的区别
Status ClearQueue(LinkQueue *Q){
    Q->rear = Q->front;
    return OK;
}
void visit(ElemType e){
    printf("%c  ", e);
}

int main()
{
    LinkQueue Q;
    ElemType e;
    InitQueue(&Q);
    QueueEmpty(&Q);
    printf("请输入字符添加到队列里(回车键结束输入)：");
    while(1){

        scanf("%c", &e);
        if(e == 10){
            break;
        }
        EnQueue(&Q, e);
    }
    QueueEmpty(&Q);
    printf("队列的长度：%d\n",QueueLength(Q));
    GetHead(Q, &e);
    printf("队头元素的值是：%c\n", e);
    QueueTraverse(Q);
    DeQueue(&Q, &e);
    printf("删除后的队列的长度：%d\n",QueueLength(Q));
    GetHead(Q, &e);
    printf("删除后的队头元素的值是：%c\n", e);
    QueueTraverse(Q);
    ClearQueue(&Q);
    printf("清空后的队列的长度：%d\n",QueueLength(Q));
    DestoryQueue(&Q);
    system("pause");
    return 0;
}
